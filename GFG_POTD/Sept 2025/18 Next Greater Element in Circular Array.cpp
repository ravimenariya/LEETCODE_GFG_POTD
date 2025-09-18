class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        stack<int>stk;
        for(int i=arr.size()-2;i>=0;i--)
        {
            while(!stk.empty() && stk.top()<=arr[i])    stk.pop();
            stk.push(arr[i]);
        }
        
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top()<=arr[i])    stk.pop();
            if(stk.empty()) ans[i]=-1;
            else            ans[i]=stk.top();
            stk.push(arr[i]);
        }
        
        return ans;
    }
};
