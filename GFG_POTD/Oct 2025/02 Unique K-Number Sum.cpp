class Solution {
    void solve(int n,int k,vector<int>&arr,int sum , vector<vector<int>>&ans,int curr)
    {
        if(sum>n)   return;
        else if(sum==n)
        {
            if(arr.size()==k)   ans.push_back(arr);
            return;
        }
        else if(arr.size()>k)   return;
        
        for(int i=curr+1;i<=9;i++)
        {
            arr.push_back(i);
            solve(n,k,arr,sum+i,ans,i);
            arr.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>ans;
        
        for(int i=1;i<=9;i++)
        {
            vector<int>arr(1,i);
            solve(n,k,arr,i,ans,i);
        }
        return ans;
    }
};
