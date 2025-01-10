class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Step 1: Precompute maxFreq for words2
        vector<int> maxFreq(26, 0);
        for (string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        // Step 2: Check words1 for universality
        vector<string> result;
        for (string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;  // Stop checking if the word fails
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
