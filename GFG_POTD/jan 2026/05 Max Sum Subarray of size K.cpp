class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        long out = 0,sum = 0;
        for(int i = 0; i < arr.size() ; ++i){
            sum += arr[i];
            if(i >= k)    sum -= arr[i - k];
            out = max(out, sum);
        }
        return out;
    }
};
