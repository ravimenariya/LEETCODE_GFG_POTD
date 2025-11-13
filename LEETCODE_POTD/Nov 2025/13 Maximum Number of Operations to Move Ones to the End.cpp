class Solution {
public:
    int maxOperations(string s) {
        int ans=0,ones=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')  {
                if(i-1>0 && s[i-1]=='0')    ans+=ones;
                ones++;
            }
        }
        if(s[n-1]=='0')    ans+=ones;
        return ans;
    }
};
