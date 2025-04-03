class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>n_max(n,0);
        for(int i=n-2;i>=0;i--) n_max[i]=max(nums[i+1],n_max[i+1]);
        int p_max=nums[0];
        long long ans=0,temp;
        for(int i=1;i<n-1;i++)
        {
            if(p_max>nums[i])
            {
                temp=(long long)(p_max-nums[i])*n_max[i];
                ans=max(ans,temp);
            }
            p_max=max(p_max,nums[i]);
        }
        return ans;
    }
};
