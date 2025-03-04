
// Problem -> https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution {
  public:
    int lis(vector<int>& arr) {
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
            if(ans.back()<arr[i])   ans.push_back(arr[i]);
            else    *lower_bound(ans.begin(),ans.end(),arr[i])=arr[i];

        return ans.size();
    }
};
