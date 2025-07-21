class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3)  return s;
        string ans="";
        ans+=s[0];
        ans+=s[1];

        int j=2;
        for(int i=2;i<s.size();i++)
        {
            if(s[i]==ans[j-1] && s[i]==ans[j-2])    continue;
            ans+=s[i];
            j++;
        }
        return ans;
    }
};
