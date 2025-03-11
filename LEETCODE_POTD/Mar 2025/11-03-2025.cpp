
// Problem -> https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),l=0,r=0,v=0,ans=0;
        unordered_map<char,int>ump;
        while(r<n)
        {
            if(!ump[s[r]])  v++;
            ump[s[r]]++;
            
            while(v==3)
            {
                ans+=n-r;
                ump[s[l]]--;
                if(!ump[s[l]])  v--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
