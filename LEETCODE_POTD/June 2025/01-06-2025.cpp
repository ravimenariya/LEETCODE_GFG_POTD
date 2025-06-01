class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        int rem;
        for(int i=0;i<=min(n,limit);i++)
        {
            rem=n-i;
            if(rem > 2*limit)   continue;
            ans+= min(limit,rem) - max(0,rem - limit) +1;
        }
        return ans;
    }
};
