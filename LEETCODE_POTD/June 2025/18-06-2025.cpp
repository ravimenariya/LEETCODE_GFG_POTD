class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=3)
        {
            if((nums[i+2]-nums[i])>k)
            {
                ans.clear();
                return ans;
            }
            vector<int>v(nums.begin()+i,nums.begin()+i+3);
            ans.push_back(v);
        }
        return ans;
    }
};
