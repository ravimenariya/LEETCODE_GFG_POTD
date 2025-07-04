class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size(),l=0,r=0,unique=0,ans=0;
        unordered_map<int,int>ump;
        while(r<n)
        {
            if(ump[arr[r]]==0)  unique++;
                ump[arr[r]]++;
                
            if(unique<=k)    
            {
                int size=r-l+1;
                ans+=((size));
            }
            
            if(unique>k)
            {
                while(unique>k)
                {
                    ump[arr[l]]--;
                    if(ump[arr[l]]==0)  unique--;
                    l++;
                }
                if(unique<=k)    
                {
                    int size=r-l+1;
                    ans+=(size);
                }
            }
            r++;
        }
        return ans;
    }
};
