class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        long long even_sum=0,odd_sum=0,n=arr.size(),l_odd=0,l_even=0;
        for(int i=0;i<n;i+=2)   even_sum+=arr[i];
        for(int i=1;i<n;i+=2)   odd_sum+=arr[i];
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(i%2==0)    even_sum-=arr[i];
            else          odd_sum-=arr[i];
            
            if((l_even+odd_sum)==(l_odd+even_sum))  ans++;
            
            if(i%2==0)    l_even+=arr[i];
            else          l_odd+=arr[i];
        }
        return ans;
    }
};
