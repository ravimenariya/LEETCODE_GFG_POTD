class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),i=0,ans=0,prev_count=0,prev_ele=nums[0];
        while(i<n)
        {
            int t=nums[i],count=0;
            while(i<n && nums[i]==t)
            {
                count++;
                i++;
            }    
            if(t-prev_ele==1)    
                ans=max(ans,prev_count+count);
            prev_ele=t;
            prev_count=count;
        }
        return ans;
    }
};
