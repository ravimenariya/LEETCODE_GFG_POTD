class Solution {
public:
    long long flowerGame(int n, int m) {
        // return (long long)m*n/2;  even this also works
        
        long long ans=0;
        if(n>m) swap(n,m);
        for(int i=1;i<=n;i++)
            ans+=(i/2 + ceil((m-i)/2.0));
        return ans;
    }
};
