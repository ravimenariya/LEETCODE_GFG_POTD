class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size(),curr=0;
        vector<int>v(32,n);
        for(int i=n-1;i>=0;i--)
        {
            curr=curr|nums[i];
            int c=1,maxidx=i;
            for(int k=31;k>=0;k--)
            {
                if(nums[i]&c)   v[k]=i;
                if(curr&c)      maxidx=max(maxidx,v[k]); 
                c=c<<1;
            }
            nums[i]=maxidx-i+1;
        }
        return nums;
    }
};
