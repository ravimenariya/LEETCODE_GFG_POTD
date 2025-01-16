class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x2=0;
        for(int&a:nums2)    x2^=a;
        int x1=0;
        for(int&a:nums1)    x1^=a;
        
        if(nums2.size()%2==0)
        {
            if(nums1.size()%2==0)   return 0;
            else    return x2;
        }
        else
        {
            if(nums1.size()%2==0)   return x1;
            else    return x1^x2;
        }
    }
};
