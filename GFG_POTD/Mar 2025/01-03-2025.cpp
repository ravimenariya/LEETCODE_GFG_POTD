
// Problem -> https://www.geeksforgeeks.org/problems/decode-the-string2444/1

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
                while(stk.top()!='[')
                {
                    k+=stk.top();
                    stk.pop();
                }
                stk.pop();
                string ns="";
                while(!stk.empty() && 48<=stk.top()&&stk.top()<=57)
                {
                    ns+=stk.top();
                    stk.pop();
                }
                int i=ns.size()-1,num=0;
                while(i>=0)
                {
                    num=num*10+ns[i]-48;
                    i--;
                }
                while(num--)
                {
                    int i=k.size()-1;
                    while(i>=0)
                    {
                        stk.push(k[i]);
                        i--;
                    }
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
