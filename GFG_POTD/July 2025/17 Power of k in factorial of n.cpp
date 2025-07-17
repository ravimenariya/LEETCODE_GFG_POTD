class Solution {
  public:
    int maxKPower(int n, int k) {
        // code here
         unordered_map<int, int> prime_factors;
        int temp = k;
        for (int i = 2; i * i <= temp; ++i) {
            while (k % i == 0) {
                prime_factors[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            prime_factors[k]++;
        }

        // Step 2: Count exponent of each prime in n!
        auto count_in_factorial = [](int n, int p) {
            int count = 0;
            while (n > 0) {
                n /= p;
                count += n;
            }
            return count;
        };

        // Step 3: Compute minimum (count in n!) / (count in k)
        int result = INT_MAX;
        for (const auto& factor : prime_factors) {
            int p = factor.first;
            int a = factor.second;
            int count = count_in_factorial(n, p);
            result = min(result, count / a);
        }

        return result;
    }
};
