class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>left(n),right(n);
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && arr[stk.top()]>=arr[i])
                stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && arr[stk.top()]>arr[i])        
                stk.pop();
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        int ans=0,count;
        for(int i=0;i<n;i++)
        {
            int l=i-(left[i]+1),r=right[i]-1-i;
            count=l+r+l*r+1;
            ans+=(count*arr[i]);
        }
        return ans;
    }
};
