class Solution {
public:
    bool check(string&a,string&b)
    {
        if(a.size()>b.size())   return false;
        for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])  return false;
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            if(check(pref,words[i]))    ans++;
        }
        return ans;
    }
};
