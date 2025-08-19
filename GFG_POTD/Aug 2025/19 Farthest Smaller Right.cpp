class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        vector<pair<int,int>>v;
        int n=arr.size();
        for(int i=0;i<n;i++)   v.push_back({arr[i],i});
        sort(v.begin(),v.end());
        
        vector<int>idx;
        int maxi=-1;
        for(auto i:v){
            idx.push_back(maxi);
            maxi=max(maxi,i.second);
        }
        
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(idx[i]>v[i].second) ans[v[i].second]=idx[i];    
        }
        return ans;
    }
};
