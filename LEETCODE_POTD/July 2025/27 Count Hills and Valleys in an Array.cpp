class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0,i=1,n=nums.size();
        while(i<n && nums[i]==nums[0])   i++;
        while(i<(n-1)){
            int prev=i-1;
            while(i<(n-1) && nums[i]==nums[i+1])   i++;
            if(i==(n-1))    break;
            if((nums[prev]<nums[i] && nums[i]>nums[i+1]) || (nums[prev]>nums[i] && nums[i]<nums[i+1]))  ans++;
            i++;
        }
        return ans;
    }
};
