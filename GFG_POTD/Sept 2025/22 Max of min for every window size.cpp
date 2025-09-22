class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n=arr.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>stk;
        
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && arr[stk.top()]>=arr[i])    stk.pop();
            if(!stk.empty())    left[i]=stk.top();
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && arr[stk.top()]>=arr[i])    stk.pop();
            if(!stk.empty())    right[i]=stk.top();
            stk.push(i);
        }
        
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int k_min=right[i]-left[i]-1;
            ans[k_min-1]=max(ans[k_min-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
            ans[i]=max(ans[i],ans[i+1]);
        
        return ans;
    }
};
