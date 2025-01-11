class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())  return false;
        vector<int>v(26,0);
        for(char&c:s)   v[c-'a']++;
        int odd=0;
        for(int i=0;i<26;i++)   if(v[i]%2)  odd++;
        if(odd>k)   return false;
        return true;
    }
};
