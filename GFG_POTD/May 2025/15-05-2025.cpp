class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        vector<int>freq(26,0);
        int ans=0;
        for(char&c:s)   freq[c-'a']++;
        for(int&f:freq) ans+=((f-2)*(f-1))/2 + f-1;
        return ans+s.size();
    }
};
