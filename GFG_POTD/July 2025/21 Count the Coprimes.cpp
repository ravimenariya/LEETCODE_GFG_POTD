#include <vector>
class Solution {
    const int MAX = 10001;
public:
    int cntCoprime(vector<int>& arr) {
        vector<int> freq(MAX, 0);
        for (int num : arr) {
            freq[num]++;
        }

        vector<int> divisible(MAX, 0);
        for (int i = 1; i < MAX; ++i) {
            for (int j = i; j < MAX; j += i) {
                divisible[i] += freq[j];
            }
        }

        vector<int> mobius(MAX, 1);
        vector<bool> isPrime(MAX, true);
        for (int i = 2; i < MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i; j < MAX; j += i) {
                    mobius[j] *= -1;
                    isPrime[j] = false;
                }
                for (int j = i * i; j < MAX; j += i * i) {
                    mobius[j] = 0;
                }
            }
        }

        int total = 0;
        for (int i = 1; i < MAX; ++i) {
            int cnt = divisible[i];
            if (cnt >= 2) {
                total += mobius[i] * (1LL * cnt * (cnt - 1) / 2);
            }
        }

        return (int)total;
    }
};
