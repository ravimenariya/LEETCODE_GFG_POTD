
// Problem -> https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2025-03-26

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(auto&i:grid)
            for(int&j:i)
                v.push_back(j);
        sort(v.begin(),v.end());
        int n=v.size(),ans=0,l=0,r=n-1,ldiff,rdiff;
        while(l<(r-1))
        {
            if(v[l]==v[r])  return ans;
            ldiff=v[l+1]-v[l];
            rdiff=v[r]-v[r-1];
            if(ldiff%x!=0 || rdiff%x!=0)   return -1;
            ldiff/=x;
            rdiff/=x;
            ans+=l*ldiff+ldiff;
            ans+=(n-r-1)*rdiff+rdiff;
            l++;
            r--;
        }
        if(l!=r)
        {
            ldiff=v[r]-v[l];
            if(ldiff%x!=0)   return -1;
            ldiff/=x;
            int a=l*ldiff+ldiff;
            int b=(n-r-1)*ldiff+ldiff;
            ans+=min(a,b);
        }
        return ans;
    }
};
