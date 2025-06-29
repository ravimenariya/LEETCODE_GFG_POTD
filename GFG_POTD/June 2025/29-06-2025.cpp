class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        // code here
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int part=1;
            int sum=0;
            for(int i=0;i<arr.size();i++){
                if(sum+arr[i]>mid){
                    part++;
                    sum=arr[i];
                }
                else sum+=arr[i];
            }
            if(part<=k){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};
