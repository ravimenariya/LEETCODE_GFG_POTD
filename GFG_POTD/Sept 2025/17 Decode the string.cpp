class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char>stk;
        for(char c:s)
        {
            if(c==']')
            {
                string k="";
                while(stk.top()!='[') {
                    k+=stk.top();
                    stk.pop();
                }
                stk.pop();
                
                string ns="";
                while(!stk.empty() && 48<=stk.top()&&stk.top()<=57)
                {
                    ns=stk.top()+ns;
                    stk.pop();
                }
                
                int num=stoi(ns);
                while(num--)
                {
                    int i=k.size()-1;
                    while(i>=0)            stk.push(k[i--]);
                }
            }
            else stk.push(c);
        }
        
        string ans="";
        while(!stk.empty())
        {
            ans=stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};
