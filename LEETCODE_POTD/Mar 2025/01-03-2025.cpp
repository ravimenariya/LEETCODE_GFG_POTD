
// Problem -> https://leetcode.com/problems/apply-operations-to-an-array/?envType=daily-question&envId=2025-03-01

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int l=0,r=n-1;
        while(l<r)
        {
            while(l<n && nums[l]>0) l++;
            r=l+1;
            while(r<n && nums[r]==0)    r++;
            if(l==n || r==n)    break;
            swap(nums[l],nums[r]);
        }
        return nums;
    }
};
