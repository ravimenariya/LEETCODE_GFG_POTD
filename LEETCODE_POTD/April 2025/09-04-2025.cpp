class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=-1,min=INT_MAX;
        vector<bool>v(101,false);
        for(auto i:nums)
            if(!v[i])
            {
                v[i]=true;
                ans++;
                if(i<min)   min=i;
            }
        if(k>min)   return -1;
        if(k==min)  return ans;
        return ans+1;
    }
};
