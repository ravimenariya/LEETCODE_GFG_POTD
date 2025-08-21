class Solution {
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
         sort(arr.begin(),arr.end());
         
        auto possible=[&](int mid){
            int prev=arr[0],count=1;
            for(int i:arr)
            {
                if((i-prev)>=mid){
                    prev=i;
                    count++;
                }
                if(count==k)    return true;
            }
            return false;
        };
        
         int low=0,high=arr.back()-arr.front(),ans=0;
         
         while(low<=high)
         {
             int mid=low+(high-low)/2;
             
             if(possible(mid)){
                 ans=mid;
                 low=mid+1;
             }
             else   high=mid-1;
         }
         return ans;
    }
};
