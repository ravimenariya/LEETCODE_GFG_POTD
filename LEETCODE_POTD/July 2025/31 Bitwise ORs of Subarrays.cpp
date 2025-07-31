class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        unordered_set<int> result_ors, current_ors;
        for (int x : arr) {
            unordered_set<int> next_ors;
            next_ors.insert(x);
            for (int y : current_ors)        next_ors.insert(x | y);
            result_ors.insert(next_ors.begin(), next_ors.end());
            current_ors = next_ors;
        }
        return result_ors.size();
    }
};
