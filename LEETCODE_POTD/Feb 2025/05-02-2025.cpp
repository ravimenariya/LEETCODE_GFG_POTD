
// Problem -> https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=daily-question&envId=2025-02-05

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size())    return false;
        vector<int>v(26,0);
        int swaps=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
                swaps++;
            v[s1[i]-'a']++;
            v[s2[i]-'a']--;
        }
        for(int&i:v)
            if(i!=0)
                return false;
        if(swaps && swaps!=2) return false;
        return true;
    }
};
