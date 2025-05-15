class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int skip=2;
        vector<string>ans;
        for(int i=0;i<groups.size();i++)
            if(groups[i]==skip) continue;
            else
            {
                ans.push_back(words[i]);
                skip=groups[i];
            }
        return ans;
    }
};
