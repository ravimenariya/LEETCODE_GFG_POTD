
// problem -> https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        stack<pair<int,int>>stk;
        vector<int>left(arr.size(),1);
        for(int i=0;i<arr.size();i++)
        {
            while(!stk.empty() && stk.top().first>=arr[i])  
            {
                left[i]+=left[stk.top().second];
                stk.pop();
            }
            stk.push({arr[i],i});
        }
        
        while(!stk.empty()) stk.pop();
        
        vector<int>right(arr.size(),1);
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top().first>=arr[i])  
            {
                right[i]+=right[stk.top().second];
                stk.pop();
            }
            stk.push({arr[i],i});
        }
        
        int ans=0,curr;
        for(int i=0;i<arr.size();i++)
        {
            curr=arr[i]*(left[i]+right[i]-1);
            ans=max(ans,curr);
        }
        return ans;
    }
};
