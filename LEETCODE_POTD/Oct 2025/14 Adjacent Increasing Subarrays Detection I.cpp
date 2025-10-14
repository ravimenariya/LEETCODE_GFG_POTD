class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),st=0;
        vector<bool>v(n,false);

        for(int i=0;i<=n-k;i++)
        {
            int f=0;
            for(int j=i+1;j<(i+k);j++){
                if(nums[j]<=nums[j-1]){
                    f=1;
                    break;
                }
            }
            if(!f)  v[i]=true;
            if(i-k>=0 && v[i] && v[i-k])    return true;
        }
        return false;
    }
};
