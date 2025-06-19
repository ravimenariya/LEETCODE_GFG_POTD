class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int m=nums[0],c=1;
        for(int i:nums)
            if((i-m)>k) {
                m=i;
                c++;
            }
        return c;
    }
}; 
