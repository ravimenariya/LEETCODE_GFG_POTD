class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int> ump = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if((i+1)<n && ump[s[i]]<ump[s[i+1]])    ans+=ump[s[i+1]]-ump[s[i++]];
            else    ans+=ump[s[i]];
        }
        return ans;
    }
};
