class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int l=0,r=arr.size()-1,m,diff;
        while(l<=r){
            m=l+(r-l)/2;
            diff=arr[m]-m-1;
            if(diff<k) l=m+1;
            else            r=m-1;
        }
        
        if(r==-1)   return k;
        return arr[r] + k-(arr[r]-r-1);
    }
};
