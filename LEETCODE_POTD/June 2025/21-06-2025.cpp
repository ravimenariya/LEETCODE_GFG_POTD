class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char ch : word) freq[ch]++;
        
        vector<int> vals;
        for (auto& p : freq) vals.push_back(p.second);
        sort(vals.begin(), vals.end());
        
        int res = INT_MAX, n = vals.size(), total = accumulate(vals.begin(), vals.end(), 0);
        
        for (int i = 0; i < n; ++i) {
            int base = vals[i], keep = 0;
            for (int j = i; j < n; ++j) {
                keep += min(vals[j], base + k);
            }
            res = min(res, total - keep);
        }
        
        return res;
    }
};
