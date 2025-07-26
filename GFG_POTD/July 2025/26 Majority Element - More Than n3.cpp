class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size(),m=n/3;
        map<int,int>mp;
        
        for(auto& i:arr)
        mp[i]++;
        
        vector<int>ans;
        
        for(auto&i :mp)
        if(i.second>m)
        ans.push_back(i.first);
        
        return ans;
    }
};
