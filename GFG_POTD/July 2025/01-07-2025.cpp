class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.size(),l=0,r=0,unique=0,ans=0;
        vector<int>freq(26,0);
        while(r<(k-1))
        {
            if(freq[s[r]-'a']==0)   unique++;
            freq[s[r]-'a']++;
            r++;
        }
        while(r<n)
        {
            if(freq[s[r]-'a']==0)   unique++;
            freq[s[r]-'a']++;
            r++;
            
            if(unique==(k-1))   ans++;
            
            freq[s[l]-'a']--;
            if(freq[s[l]-'a']==0)   unique--;
            l++;
        }
        return ans;
    }
};
