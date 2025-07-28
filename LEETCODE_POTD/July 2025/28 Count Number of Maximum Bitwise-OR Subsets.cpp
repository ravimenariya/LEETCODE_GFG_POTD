class Solution {
    int ans=0;
    void solve(int n,vector<int>&nums,int i,int curr,int&maxor)
    {
        if(i>=n) {
            if(curr==maxor)  ans++;
            return;
        }   
        solve(n,nums,i+1,curr,maxor);
        curr=curr|nums[i];
        solve(n,nums,i+1,curr,maxor);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(int i:nums) maxor=maxor|i;
        solve(nums.size(),nums,0,0,maxor);
        return ans;
    }
};
