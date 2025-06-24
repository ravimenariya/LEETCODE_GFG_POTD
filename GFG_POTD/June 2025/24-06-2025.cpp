class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<char>stk;
        int i=0,n=s.size();
        while(i<n) {
            if(!stk.empty() && s[i]>stk.top()){
                stk.pop();
                if(--k==0)    break;
            }
            else                stk.push(s[i++]);
        }
        
        while(!stk.empty() && k--)      stk.pop();
        string ans="";
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        while(i<n)          ans+=s[i++];
        
        return ans;
    }
};
