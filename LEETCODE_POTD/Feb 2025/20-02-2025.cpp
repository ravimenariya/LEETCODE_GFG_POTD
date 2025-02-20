
// Problem -> https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2025-02-20

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int m=n;
        string ans="";
        while(m--)  ans+='0';
        sort(nums.begin(),nums.end());
        for(string i:nums)   
        {
            if(ans!=i)  return ans;
            int j=n-1;
            while(j>=0 && ans[j]=='1')
            {
                ans[j]='0';
                j--;
            }
            if(j>=0 && ans[j]=='0') ans[j]='1';
        }
        return ans;
        
    }
};
