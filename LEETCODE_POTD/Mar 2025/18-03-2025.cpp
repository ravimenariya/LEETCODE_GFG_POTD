
// Prblem -> https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size(),l=0,r=1,ans=1,curr=nums[0];
        while(r<n)
        {
            if((curr & nums[r])==0)
            {
                curr=curr | nums[r];
                r++;
                if((r-l)>ans)   ans=r-l;
            }
            else if(l<r)
            {
                curr=curr ^ nums[l];
                l++;
            }
        }
        return ans;
    }
};
