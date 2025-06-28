class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)  v.push_back({nums[i],i});
      sort(v.begin(),v.end());
      int j=nums.size()-1;
      vector<pair<int,int>>ans;
      while(k)
      {
        ans.push_back(v[j--]);
        k--;
      }
      sort(ans.begin(),ans.end(),[&](pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
      });
      vector<int>res;
      for(auto i:ans)   res.push_back(i.first);
      return res;
    }
};
