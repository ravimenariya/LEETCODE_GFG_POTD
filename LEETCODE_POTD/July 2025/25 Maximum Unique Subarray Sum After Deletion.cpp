class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxsum=0;
        unordered_map<int,int>ump;
        for(int i:nums)  ump[i]++;
        for(auto i:ump) if(i.first>0) maxsum+=i.first;
        if(!maxsum) return *max_element(nums.begin(),nums.end());
        return maxsum;
    }
};
