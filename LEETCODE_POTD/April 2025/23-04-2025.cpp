class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>ump;
        int m=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            int sum=0,t=i;
            while(t)
            {
                sum+=t%10;
                t/=10;
            }
            if(++ump[sum]==m) ans++;
            else if(ump[sum]>m)  
            {
                m=ump[sum];
                ans=1;
            }
        }
        return ans;
    }
};
