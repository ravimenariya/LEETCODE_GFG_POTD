class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        vector<int>v;
        int ans=0;
        for(int&i:arr){
            auto p=upper_bound(v.begin(),v.end(),i);
            ans+=v.end()-p;
            v.insert(p,i);
        }
        return ans;
    }
};
