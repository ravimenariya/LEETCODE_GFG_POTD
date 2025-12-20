class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int l=0,r=arr.size()-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            if(arr[m]==k)   return m;
            else if(arr[m]<k)   l=m+1;
            else                r=m-1;
        }
        return l;
    }
};
