
// Problem ->  https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0 ,m=1;
        while(i<(n-1))
        {
            int c=1;
            while(i<(n-1) && nums[i]<nums[i+1])
            {
                c++;
                i++;
            }
            m=max(m,c);
            c=1;
          
            while(i<(n-1) && nums[i]>nums[i+1])
            {
                i++;
                c++;
            }
            
            while(i<(n-1) && nums[i]==nums[i+1])           i++;

            m=max(m,c);
        }
        return m;
    }
};
