
// Problem ->  https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/submissions/1571714560/?envType=daily-question&envId=2025-03-12

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=0,p=0;
        for(int&i:nums)
        if(i<0) n++;
        else if (i>0)   p++;
        return max(n,p);
    }
};
