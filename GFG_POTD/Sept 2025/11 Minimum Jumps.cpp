class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int i=0,n=arr.size(),maxi=0,count=0;
        while(i<n)
        {
            int k=1,far_i=0,maxstep=arr[maxi];
            count++;
            if((i+maxstep)>=(n-1))  return count;
            while(k<=maxstep && (i+k)<n)
            {
                if(arr[i+k] && (arr[i+k]+i+k)>=far_i)
                {
                    far_i=arr[i+k]+i+k;
                    maxi=i+k;
                }
                k++;
            }
            if(far_i==0)  return -1;
            i=maxi;
        }
        return count;
    }
};
