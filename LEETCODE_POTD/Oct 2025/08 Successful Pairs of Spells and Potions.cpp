class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size(),m=potions.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            long long target=ceil(success/(double)spells[i]);
            int low=0,high=m-1,mid;
            while(low<=high)
            {
                mid=low+(high-low)/2;
                if(potions[mid]>=target)    high=mid-1;
                else    low=mid+1;
            }
            ans[i]=m-low;
        }
        return ans;
    }
};
