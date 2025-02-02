
// problem -> https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2025-02-02

class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<(n-1) && nums[i]<=nums[i+1])    i++;
        if(i==(n-1)) return true;
        i++;
        while(i<(n-1) )
            if(nums[i]>nums[i+1])   return false;
            else    i++;
        
        if(nums[i]<=nums[0])    return true;
        return false;
    }
};
