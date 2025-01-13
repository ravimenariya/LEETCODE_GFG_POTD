class Solution {
public:
    int minimumLength(string s) {
        if(s.size()<3)  return s.size();
        unordered_map<char,int>right;
        unordered_map<char,int>left;
        for(char&c:s)   right[c]++;
        int n=0;
        for(int i=0;i<s.size();i++)
        {
            right[s[i]]--;
            if(right[s[i]]>0 && left[s[i]]>0)
            {
                right[s[i]]--;
                left[s[i]]--;
                n+=2;
            }
            left[s[i]]++;
        }
        return s.size()-n;
    }
};
