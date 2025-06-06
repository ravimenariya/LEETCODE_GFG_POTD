class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
        long long hashcode=0,code=0;
        long long mod=10e9+7;
        for(char&c:pat)     hashcode=((hashcode*10)%mod + (c-'a'+1))%mod;
        
        int i=0,n=pat.size();
        vector<int>ans;
        for(;i<n;i++)        code=(code*10)%mod + (txt[i]-'a'+1);
        if(code==hashcode)  ans.push_back(1);
        
        long long b2 = 1;
        for (int i = 1; i < n; i++)        b2 = (b2 * 10) % mod;
        
        for(;i<txt.size();i++)
        {
            code=code-((txt[i-n]-'a'+1)*b2);
            code=(((code*10)%mod + (txt[i]-'a'+1))%mod + mod)%mod;
            if(code==hashcode)  ans.push_back(i-n+2);
        }
        return ans;
    }
};
