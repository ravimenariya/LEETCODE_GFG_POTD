class Solution {
public:
    long long countValid(int n, vector<int>& arr) {
        long long total_n_digits = pow(10, n - 1) * 9;
        long long step = 9 - arr.size();

        if (find(arr.begin(), arr.end(), 0) != arr.end()) {
            step++;
        }

        long long allowed_permutations = 0;
        if (step > 0) {
            allowed_permutations = step * pow(10 - arr.size(), n - 1);
        }
        
        return total_n_digits - allowed_permutations;
    }
};
