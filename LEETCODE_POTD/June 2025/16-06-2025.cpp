class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1,mn=INT_MAX;
        for(int&i:nums) 
            if(i<mn)    mn=i;
            else if(i!=mn)      ans=max(ans,i-mn);
        return ans;
    }
};
