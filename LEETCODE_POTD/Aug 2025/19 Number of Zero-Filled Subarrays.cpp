class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int i=0,n=nums.size();
        while(i<n)
        {
            int count=0;
            while(i<n && nums[i]==0){
                count++;
                i++;
            }
            long long sub=((long long)count*(count+1))/2;
            ans+=sub;
            i++;
        }
        return ans;
    }
};
