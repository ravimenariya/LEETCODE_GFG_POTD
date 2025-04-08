class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool>f(101,false);
        int n=nums.size(),i;
        for(i=n-1;i>=0;i--)
            if(f[nums[i]])    break;
            else              f[nums[i]]=true;
        return ceil((i+1)/3.0);
    }
};
