
//problem -> https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=nums[0],currsum=nums[0];
        for(int i=1;i<nums.size();i++)
            if(nums[i]>nums[i-1])
                currsum+=nums[i];
            else {
                ans=max(ans,currsum);
                currsum=nums[i];
            }
        return max(ans,currsum);
    }
};
