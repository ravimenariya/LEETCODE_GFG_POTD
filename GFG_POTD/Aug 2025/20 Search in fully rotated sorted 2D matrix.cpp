class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int low=0,high=n*m-1,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            int le=mat[low/m][low%m];
            int me=mat[mid/m][mid%m];
            int he=mat[high/m][high%m];
            
            if(me==x)   return true;
            else if(le<=me ){
                if(le<=x && x<=me)  high=mid-1;
                else                low=mid+1;
            }   
            else {
                if(me<=x && x<=he)  low=mid+1;
                else                high=mid-1;
            }
        }
        return false;
    }
};
