
// Problem -> https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution {
  public:
    int lis(vector<int>& arr) {
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(ans.back()<arr[i])   ans.push_back(arr[i]);
            else
                for(int j=0;j<ans.size();j++)
                    if(ans[j]>=arr[i])
                    {
                        ans[j]=arr[i];
                        break;
                    }
        }
        return ans.size();
    }
};
