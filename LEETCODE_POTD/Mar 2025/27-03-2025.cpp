
// Problem -> https://leetcode.com/problems/minimum-index-of-a-valid-split/?envType=daily-question&envId=2025-03-27

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>freq;
        int dom=0,domf=0;
        for(int&i:nums) 
        {
            freq[i]++;
            if(freq[i]>domf)    
            {
                domf=freq[i];
                dom=i;
            }
        }
        int n=nums.size(),curr=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==dom)
            {
                curr++;
                if(curr>((i+1)/2) && (domf-curr)>((n-i-1)/2))   return i;
            }
        }
        return -1;
    }
};

