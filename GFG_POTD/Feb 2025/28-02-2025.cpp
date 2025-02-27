
// Problem -> https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>stk;
        for(string i:arr)
        {
            if(i=="*" || i=="+" || i=="-" || i=="/")
            {
                int a=stk.top();
                stk.pop();
                int b=stk.top();
                stk.pop();
                if(i=="*")  stk.push(b*a);
                else if(i=="+") stk.push(b+a);
                else if(i=="-") stk.push(b-a);
                else if(i=="/") stk.push(b/a);
            }
            else    stk.push(stoi(i));
        }
        return stk.top();
    }
};
