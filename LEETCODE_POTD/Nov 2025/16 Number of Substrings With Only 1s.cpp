class Solution {
public:
    int numSub(string s) {
        int last=s[0]-'0',ans=last;
        long long mod=1e9+7;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                if(s[i-1]=='1')   last=((last%mod)+1)%mod;
                else last=1;
                ans=((long long)ans+last)%mod;
            }
        }
        return ans;
    }
};
