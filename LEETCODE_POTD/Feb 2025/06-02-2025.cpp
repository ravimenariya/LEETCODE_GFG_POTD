
// Problem ->  https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,vector<pair<int,int>>>ump;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                ump[nums[i]*nums[j]].push_back({nums[i],nums[j]});
        int ans=0;
        for(auto&i:ump)
        {
            int n= i.second.size();
            n=((n*(n-1))/2);
            ans+=n*8;
        }
        return ans;
    }
};
