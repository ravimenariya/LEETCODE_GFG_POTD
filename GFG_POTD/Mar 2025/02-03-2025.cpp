
// Problem -> https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int>q;
        int n=arr.size();
        q.push_back(0);
        for(int i=1;i<k;i++)
        {
            while(!q.empty() && arr[q.back()]<=arr[i]) q.pop_back();
            q.push_back(i);
        }
        vector<int>ans;
        ans.push_back(arr[q.front()]);
        for(int i=k;i<n;i++)
        {
            while(!q.empty() && arr[q.back()]<=arr[i]) q.pop_back();
            q.push_back(i);
            if(q.front()<=(i-k))    q.pop_front();
            ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};
