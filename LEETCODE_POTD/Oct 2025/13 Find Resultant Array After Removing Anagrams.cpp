class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<char,int>prev;
        vector<string>ans;
        for(auto str: words)
        {
            unordered_map<char,int>curr;
            for(char c:str) curr[c]++;
            if(prev!=curr){
                prev=curr;
                ans.push_back(str);
            }
        }
        return ans;
    }
};
