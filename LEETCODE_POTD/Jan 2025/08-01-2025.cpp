class Solution {
public:
    bool solve(const string&a,const string&b)
    {
        if(a.size()>b.size())   return false;
        for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])  return false;
        int j=b.size()-1;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]!=b[j])  return false;
            j--;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++)
            for(int j=i+1;j<words.size();j++)
                if(i!=j && solve(words[i],words[j]))
                    ans++;
        return ans;
    }
};
