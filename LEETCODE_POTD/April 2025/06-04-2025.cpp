class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<=i-1;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;;
                    hash[i]=j;
                }
            }
        }
        int maxi=-1;
        int ind=-1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(maxi<dp[i]){
                maxi=dp[i];
                ind=i;
            }
        }
        ans.push_back(nums[ind]);
        while(hash[ind]!=ind){
            ind=hash[ind];
            ans.push_back(nums[ind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
