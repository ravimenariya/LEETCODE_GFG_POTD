class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int ans=0,i=0,j=0,n=arr.size(),count=0,zeroes=0;
        while(j<n)
        {
            if(arr[j])  count++;
            else {
                if(zeroes<k){
                    zeroes++;
                    count++;
                }
                else {
                    while(arr[i]!=0){
                        count--;
                        i++;
                    }
                    i++;
                }
            }
            ans=max(ans,count);
            j++;
        }
        return ans;
    }
};
