
//problem -> https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)    if(nums[i]%2==nums[i+1]%2)  return false;
        return true;
    }
};
