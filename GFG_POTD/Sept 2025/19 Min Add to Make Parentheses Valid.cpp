class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char>stk;
        for(char c:s)
        {
            if(c==')' && !stk.empty() && stk.top()=='(')    stk.pop();
            else stk.push(c);
        }
        return stk.size();
    }
};
