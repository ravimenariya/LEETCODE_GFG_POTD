class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int n=happiness.size(),t=0;
        long long sum=0;
        for(int i=n-1;i>=n-k;i--){
            sum+=max(0,happiness[i]-t);
            t++;
        }
        return sum;
    }
};
