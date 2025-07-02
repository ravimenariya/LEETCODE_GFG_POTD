class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size(),l=0,r=0,unique=0,ans=0;
        unordered_map<int,int>ump;
        while(r<n)
        {
            if(ump[arr[r]]==0)  unique++;
                ump[arr[r]]++;
                
            if(unique<=2)    ans=max(ans,r-l+1);
            
            while(unique>2)
            {
                ump[arr[l]]--;
                if(ump[arr[l]]==0)  unique--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
