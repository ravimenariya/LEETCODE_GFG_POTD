class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroes=0,l=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!nums[i])    zeroes++;
            if(zeroes>1)
            {
                while(nums[l]!=0)   l++;
                l++;
                zeroes--;
            }
            ans=max(ans,i-l);
        }
        return ans;
    }
};
