class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=INT_MIN,n=energy.size();
        for(int st=n-1;st>=n-k;st--)
        {
            int sum=0;
            for(int i=st;i>=0;i-=k)
            {
                sum+=energy[i];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
