
/*

problem -> https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

Longest valid Parentheses

Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.

*/

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int n=s.size();
        vector<int>v(n,0);
        
        stack<pair<char,int>>stk;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')   stk.push({s[i],i});
            else if(!stk.empty() && stk.top().first=='(')
            {
                v[stk.top().second]=1;
                v[i]=1;
                stk.pop();
            }
        }
        int ans=0, i=0,count;
        while(i<n)
        {
            count=0;
            while(i<n && v[i]==1)
            {
                count++;
                i++;
            }
            ans=max(ans,count);
            i++;
        }
        return ans;
    }
};
