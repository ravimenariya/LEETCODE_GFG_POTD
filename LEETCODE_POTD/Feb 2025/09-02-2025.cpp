
// Problem -> https://leetcode.com/problems/count-number-of-bad-pairs/description/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long>ump;
        for(int i=0;i<nums.size();i++)
            ump[nums[i]-i]++;
        
        long long ans=0;
        for(auto&i:ump)
            ans+=((i.second*(i.second-1))/2);
        
        ans=((long long)(nums.size()*(nums.size()-1))/2)-ans;
        return ans;
    }
};
