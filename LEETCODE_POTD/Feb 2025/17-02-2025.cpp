
// Problem -> https://leetcode.com/problems/letter-tile-possibilities/?envType=daily-question&envId=2025-02-17

class Solution {
    void backtrack(unordered_map<char, int>& freq, int& ans) {
        for (auto& [ch, count] : freq) {
            if (count > 0) {
                ans++;  
                freq[ch]--;  
                backtrack(freq, ans);
                freq[ch]++;  
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) freq[ch]++;

        int ans = 0;
        backtrack(freq, ans);
        return ans;
    }
};
