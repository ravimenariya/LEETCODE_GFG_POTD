class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,count,maxele=0,i=0,n=nums.size();
        while(i<n)
        {
            if(nums[i]>=maxele)
            {
                count=0;
                if(nums[i]>maxele)  ans=0;
                maxele=nums[i];
                while(i<n && nums[i]==maxele)  {
                    count++;
                    i++;
                }
                ans=max(ans,count);
            }
            else i++;
        }
        return ans;
    }
};
