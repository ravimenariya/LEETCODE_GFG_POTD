class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        long long sum = (long long)n * (n + 1) / 2;
        long long sqsum = (long long)n * (n + 1) * (2 * n + 1) / 6;
        long long currsum = 0, currsqsum = 0;
        for (int x : arr) {
            currsum += x;
            currsqsum += (long long)x * x;
        }
        long long diff1 = sum - currsum;       
        long long diff2 = sqsum - currsqsum;   
        int b=(diff1*diff1+diff2)/(2*diff1);
        int a=b-diff1;
        return {a, b};
    }
};
