class MinStack {
public:
    MinStack() : _stack() {
        
    }
    
    void push(int val) {
        _stack.push_back(val);
    }
    
    void pop() {
        _stack.pop_back();
    }
    
    int top() {
        return _stack[_stack.size() - 1];
    }
    
    int getMin() {
        // HOW TO DO IN O(n)?
        // We could save an ordered list with the min values...
        // Let's do the naive version for now
        int min = _stack[0];
        for (auto& num : _stack) {
            if (num < min) {
                min = num;
            }
        }
        return min; 
    }

private:
    std::vector<int> _stack;
};
