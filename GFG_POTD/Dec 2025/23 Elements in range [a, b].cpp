class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        
        auto find=[&](int x,char dir){
            int l=0,r=arr.size()-1,m;
            if(dir=='l'){
                while(l<=r){
                    m=l+(r-l)/2;
                    if(arr[m]<x)   l=m+1;
                    else            r=m-1;
                }
                return l;
            }
            else {
                while(l<=r){
                    m=l+(r-l)/2;
                    if(arr[m]<=x)   l=m+1;
                    else            r=m-1;
                }
                return r;
            }
        };
        
        vector<int>ans;
        for(auto q:queries){
            int st=find(q[0],'l');
            int end=find(q[1],'r');
            ans.push_back(end-st+1);
        }
        return ans;
    }
};
