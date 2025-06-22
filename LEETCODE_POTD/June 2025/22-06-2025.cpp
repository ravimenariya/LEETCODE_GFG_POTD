class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size(),r=n%k;
        if (r)    s.append(k - r, fill);
        int i=0;
        vector<string>ans;
        while(i<n)
        {
            ans.push_back(s.substr(i,k));
            i+=k;
        }
        return ans;
    }
};
