
// Problem -> https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(int&i:nums) ump[i]++;
        for(auto&i:ump) if(i.second%2!=0)   return false;
        return true;
    }
};
