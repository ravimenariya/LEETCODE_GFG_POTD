
// problem -> https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/?envType=daily-question&envId=2025-02-27

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(), ans=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int size=1;
                int sum=arr[i]+arr[j];
                int last=arr[j];
                size++;
                for(int k=j+1;k<n;k++)
                {
                    if(arr[k]==sum)
                    {
                        size++;
                        sum=last+arr[k];
                        last=arr[k];
                    }
                }
                ans=max(ans,size);
            }
        }
        if(ans<=2)  return 0;
        return ans;
    }
};
