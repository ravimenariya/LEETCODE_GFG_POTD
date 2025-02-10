
// problem -> https://leetcode.com/problems/clear-digits/

class Solution {
public:
    string clearDigits(string s) {
        stack<char>stk;
        for(char&c:s)
        {
            if(48<=c && c<=57)  stk.pop();
            else    stk.push(c);
        }
        string ans="";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
