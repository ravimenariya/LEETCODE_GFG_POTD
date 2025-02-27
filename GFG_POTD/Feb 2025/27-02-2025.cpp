
// Problem -> https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

class Solution {
    stack<int> stk;
    stack<int> minStack;

public:
    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        stk.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (stk.empty()) return;
        if (stk.top() == minStack.top()) {
            minStack.pop();
        }
        stk.pop();
    }

    // Returns top element of the Stack
    int peek() {
        return stk.empty() ? -1 : stk.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};
