class Solution {
    void solve(vector<int>&nums,int&n,int i,int curr,int&ans)
    {
        if(i>=n)    return;
        solve(nums,n,i+1,curr,ans);
        curr ^=nums[i];
        ans+=curr;
        solve(nums,n,i+1,curr,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size(),curr=0,ans=0,i=0;
        solve(nums,n,i,curr,ans);
        return ans;
    }
};
