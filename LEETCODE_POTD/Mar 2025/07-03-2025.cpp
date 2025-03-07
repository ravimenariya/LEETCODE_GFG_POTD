
// problem -> https://leetcode.com/problems/closest-prime-numbers-in-range/?envType=daily-question&envId=2025-03-07

class Solution {
    bool prime(int n)
    {
        if(n==1)    return false;
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0)  return false;
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>v;
        for(int i=left;i<=right;i++)
            if(prime(i))    v.push_back(i);
        
        vector<int>ans={-1,-1};
        if(v.size()<2)  return ans;
        if(v.size()==2)    return v;
        int m=INT_MAX,mi=0;
        for(int i=0;i<v.size()-1;i++)
            if((v[i+1]-v[i])<m)
            {
                m=v[i+1]-v[i];
                mi=i;
            }
        ans.clear();
        ans.push_back(v[mi]);
        ans.push_back(v[mi+1]);
        return ans;
    }
};
