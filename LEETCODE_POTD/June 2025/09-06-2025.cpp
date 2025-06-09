class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr_num = 1;
        k--;

        while (k > 0) {
            long long steps = countSteps(curr_num, n);
            if (steps <= k) {
                curr_num++;
                k -= steps;
            } else {
                curr_num *= 10;
                k--;
            }
        }

        return curr_num;
    }

private:
    long long countSteps(long long curr, long long n) {
        long long steps = 0;
        long long first = curr;
        long long last = curr;

        while (first <= n) {
            steps += min(last, n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }
};
