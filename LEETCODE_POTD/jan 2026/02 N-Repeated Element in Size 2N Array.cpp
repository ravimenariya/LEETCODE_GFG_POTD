class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,bool>ump;
        for(int i=0;i<nums.size();i++){
            if(ump[nums[i]])  return nums[i];
            ump[nums[i]]=true;
        }
        return -1;
    }
};
