
/*

problem -> https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
An input string is valid if:

         1. Open brackets must be closed by the same type of brackets.
         2. Open brackets must be closed in the correct order.

*/

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>stk;
        for(char c:s)
        {
            if(c=='(' || c=='[' || c=='{')  stk.push(c);
            else
            {
                if(stk.empty()) return false;
                if(c==')' && stk.top()!='(')    return false;
                if(c==']' && stk.top()!='[')    return false;
                if(c=='}' && stk.top()!='{')    return false;
                stk.pop();
            }
        }
        if(!stk.empty())    return false;
        return true;
    }
};
