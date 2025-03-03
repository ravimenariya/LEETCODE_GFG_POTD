
// problem -> https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        int c=0;
        for(int&i:nums)
            if(i==pivot)    c++;
            else if(i<pivot)    ans.push_back(i);
        while(c--)  ans.push_back(pivot);
        for(int&i:nums)
            if(i>pivot) ans.push_back(i);
        
        return ans;
    }
};
