class MinStack {
public:
    MinStack() : _stack(), _minStack() {
        
    }
    
    void push(int val) {
        _stack.push_back(val);
        if (_minStack.size() == 0) {
            _minStack.push_back(val);
        } else {
            _minStack.push_back(std::min(_minStack[_minStack.size()-1], val));
        }
    }
    
    void pop() {
        _stack.pop_back();
        _minStack.pop_back();
    }
    
    int top() {
        return _stack[_stack.size() - 1];
    }

    int getMin() {
        return _minStack[_minStack.size()-1];
    }

private:
    std::vector<int> _stack;
    std::vector<int> _minStack;
};
