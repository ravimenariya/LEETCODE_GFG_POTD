class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int i=1,n=nums.size();
        stack<int>stk;
        stk.push(nums[0]);
        while(i<n)
        {
            int gcd=__gcd(stk.top(),nums[i]);
            while(gcd > 1)
            {
                nums[i]=((long long)stk.top()*nums[i])/gcd;
                stk.pop(); 
                if(stk.empty()) break;
                gcd=__gcd(stk.top(),nums[i]);              
            }
            stk.push(nums[i]);
            i++;
        }

        vector<int>ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
