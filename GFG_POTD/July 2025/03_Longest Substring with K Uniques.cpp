class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size(),l=0,r=0,unique=0,ans=-1;
        unordered_map<char,int>ump;
        while(r<n)
        {
            if(ump[s[r]]==0)  unique++;
                ump[s[r]]++;
                
            if(unique==k)    ans=max(ans,r-l+1);
            
            while(unique>k)
            {
                ump[s[l]]--;
                if(ump[s[l]]==0)  unique--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
