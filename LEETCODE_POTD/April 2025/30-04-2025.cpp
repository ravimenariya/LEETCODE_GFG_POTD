class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i:nums)
        {
            int c=0;
            while(i)
            {
                c++;
                i/=10;
            }
            if(c%2==0)  ans++;
        }
        return ans;
    }
};
