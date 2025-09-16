class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int>stk;
        for(auto s:arr)
        {
            if(s=="+" || s=="-" || s=="*" || s=="/" || s=="^")
            {
                int b=stk.top();
                stk.pop();
                int a=stk.top();
                stk.pop();
                
                if(s=="+")  stk.push(a+b);
                else if(s=="-") stk.push(a-b);
                else if(s=="*") stk.push(a*b);
                else if(s=="/") stk.push(floor((float)a/b));
                else if(s=="^") stk.push(pow(a,b));
            }
            else    stk.push(stoi(s));
        }
        
        return stk.top();
    }
};
