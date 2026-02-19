class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        int n=high-low+1,i;
        vector<bool>v(n,false);
        for(int&a:arr){
            i=a-low;
            if(i>=0 && i<n) v[i]=true;
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!v[i]){
                ans.push_back(i+low);
            }
        }
        
        return ans;
    }
};
