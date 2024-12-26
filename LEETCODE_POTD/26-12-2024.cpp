class Solution {
public:
    int ans=0;
    void solve(vector<int>& nums, int& target,int i,int& n,int curr)
    {
        if(i==n)  
        {
            if(curr==target)
            ans++;
            return;
        }  
        solve(nums,target,i+1,n,curr+nums[i]);
        solve(nums,target,i+1,n,curr-nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        solve(nums,target,0,n,0);
        return ans;
    }
};
