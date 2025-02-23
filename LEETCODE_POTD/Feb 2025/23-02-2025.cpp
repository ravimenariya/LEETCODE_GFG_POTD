
// problem -> https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        stack<int>stk;
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top()<=arr[i])    stk.pop();
            if(stk.empty()) ans[i]=-1;
            else    ans[i]=stk.top();
            stk.push(arr[i]);
        }
        return ans;
    }
};
