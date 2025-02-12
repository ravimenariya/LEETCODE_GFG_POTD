
// problm -> https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/submissions/1540311472/?envType=daily-question&envId=2025-02-12

class Solution {
public:
    int maximumSum(vector<int>& nums) {
       unordered_map<long long,pair<int,int>>ump;
       
       for(auto&i:nums)
       {
            long long sum=0;
            int t=i;
            while(t)
            {
                sum+=t%10;
                t/=10;
            }
            if(i> ump[sum].first)  
            {
                ump[sum].second=ump[sum].first;
                ump[sum].first =i;
            }
            else if(i>ump[sum].second)  ump[sum].second=i;
       }  
        long long msum=-1;
       for(auto&i:ump)
       {
            if(i.second.first!=0 && i.second.second!=0 && (i.second.first + i.second.second)>msum)
            msum=i.second.first + i.second.second;
       }
       return msum;
    }
};
