class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans=0,Lsum=0,Rsum=accumulate(nums.begin(),nums.end(),0);
        for(int i:nums){
            Lsum+=i;
            Rsum-=i;
            if(Rsum!=0 && abs(Lsum-Rsum)%2==0)  ans++;
        }
        return ans;
    }
};
