class Solution {
public:
    int reverse(int x) {
        std::string xString = std::to_string(x);
        auto firstCharacter = xString[xString.size()-1];
        int startIndex = xString.size() - 2;
        int endIndex = 0;
        int sign = 1;

        if (xString[0] == '-') {
            std::cout << "Negative number" << endl;

            // set the sign
            sign = -1;

            // only go to the second to front character so we ignore the negative
            endIndex = 1;
        }

        int result = sign * (firstCharacter - '0');

        cout << "i=" << (xString.size() - 1) << "," << result << endl;

        for (int i = startIndex; i>=endIndex; i--) {
            auto currentDigit = xString[i] - '0';

            // if it is greater than 10, then there is no way we can get our next digit in
            auto resultTooHigh = result > (INT32_MAX / 10);
            auto resultTooLow = result < (INT32_MIN / 10);
            if (resultTooHigh or resultTooLow) {
                return 0;
            } else if (result == (INT32_MAX / 10)) {
                if (currentDigit > (INT32_MAX % 10)) {
                    return 0;
                }
            }
            result = (result*10) + (sign*currentDigit);

            cout << "i=" << xString.size() - 1 << "," << result << endl;
        }

        return result;
    }
};
