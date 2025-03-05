
// Problem -> https://www.geeksforgeeks.org/problems/longest-string-chain/1

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int longest = 1;

        for (const string& word : words) {
            dp[word] = 1;  
            for (int i = 0; i < word.size(); ++i) {
                string prevWord = word.substr(0, i) + word.substr(i + 1);  
                if (dp.find(prevWord) != dp.end()) {
                    dp[word] = max(dp[word], dp[prevWord] + 1);
                }
            }
            longest = max(longest, dp[word]);
        }

        return longest;
    }
};
