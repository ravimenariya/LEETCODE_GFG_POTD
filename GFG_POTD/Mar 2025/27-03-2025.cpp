
// Problem -> https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int, int>> pq;
        for(int i=0;i<arr.size();i++)   pq.push_back({arr[i],i});
        sort(pq.begin(),pq.end());
        vector<int>plat;
        
        for(int k=0;k<pq.size();k++)
        {
            auto p=pq[k];
            bool f=0;
            for(int i=0;i<plat.size();i++)
            {
                if(plat[i]<p.first)
                {
                    plat[i]=dep[p.second];
                    f=1;
                    break;
                }
            }
            if(!f)  plat.push_back(dep[p.second]);
        }
        return plat.size();
    }
};
