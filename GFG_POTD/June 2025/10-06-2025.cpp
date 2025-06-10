class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int ans=0,f=0;
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            ans+=i-freq[s[i]-'a'];
            if(++freq[s[i]-'a']>1)    f=1;
        }
        return ans+f;
    }
};
