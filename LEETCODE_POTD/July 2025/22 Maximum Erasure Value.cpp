class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0,l=0,r=0,n=nums.size(),ans=0;
        unordered_map<int,bool>ump;
        while(r<n){
            while(ump[nums[r]]){
                ump[nums[l]]=false;
                sum-=nums[l];
                l++;
            }
            sum+=nums[r];
            ans=max(ans,sum);
            ump[nums[r]]=true;
            r++;
        }
        return ans;
    }
};
