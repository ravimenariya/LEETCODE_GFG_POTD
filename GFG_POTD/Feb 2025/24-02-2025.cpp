
// problem -> https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<pair<int,int>>stk;
        vector<int>ans(arr.size(),1);
        for(int i=0;i<arr.size();i++)
        {
            while(!stk.empty() && stk.top().first<=arr[i])  
            {
                ans[i]+=ans[stk.top().second];
                stk.pop();
            }
            stk.push({arr[i],i});
        }
        return ans;
    }
};
