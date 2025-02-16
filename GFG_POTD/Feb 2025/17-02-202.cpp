
// Problem -> https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int>pq;
        for(int&i:arr)  pq.push(i);
        vector<int>v;
        while(k--)
        {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};
