class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int sum=nums[i]+nums[j];
                int l=j+1,h=n-1,mid;
                while(l<=h)
                {
                    mid=l+(h-l)/2;
                    if(nums[mid]<sum)  l=mid+1;
                    else                h=mid-1;
                }
                count+=(h-j);
            }
        }
        return count;
    }
};
