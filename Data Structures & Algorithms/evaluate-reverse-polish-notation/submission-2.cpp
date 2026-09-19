class Solution {
public:
    bool isOperation(const string& token) {
        return evaluator.contains(token);
    }

    std::unordered_map<string, std::function<int(int, int)>> evaluator = {
        { "+", [](int op1, int op2) { return (op1 + op2); }},
        { "-", [](int op1, int op2) { return (op1 - op2); }},
        { "*", [](int op1, int op2) { return (op1 * op2); }},
        { "/", [](int op1, int op2) { return (op1 / op2); }},
    };

    int evaluate(const string& operation, int op1, int op2) {
        auto result = evaluator[operation](op1, op2);
        // std::cout << "Evauating " << op1 << operation << op2 << "=" << result << std::endl;
        return result;
    }

    int evalRPN(vector<string>& tokens) {
        // single part options, +, -, *, /
        stack<int> tokenStack;

        for (const auto& token : tokens) {
            // if operation, pop last two operands
            if (isOperation(token)) {
                const auto op2 = tokenStack.top();
                tokenStack.pop();
                const auto op1 = tokenStack.top();
                tokenStack.pop();
                const auto intResult = evaluate(token, op1, op2);
                // std::cout << "Adding " << intResult << "," << strResult << " to stack" << std::endl;
                tokenStack.push(intResult);
            } else {
                // std::cout << "Adding " << token << " to stack" << std::endl;
                tokenStack.push(stoi(token));
            }
        }
        return tokenStack.top();
    }
};
