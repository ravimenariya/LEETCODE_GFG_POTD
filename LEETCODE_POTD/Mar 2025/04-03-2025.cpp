
// Problem -> https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-03-04

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int mp=pow(3,16);
        while(mp && n)
        {
            if(n>=mp)   n-=mp;
            mp/=3;
        }
        if(!n)  return true;
        return false;
    }
};
