
// Problem ->  https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size(),st=0,prev=colors[0],i=1,curr=1,ans=0;
        while(st<n)
        {
            if(colors[i]!=prev)
            {
                curr++;
                if(curr>=k) 
                {
                    ans++;
                    st++;
                }
            }
            else
            {
                curr=1;
                if(st>i)    break;
                st=i;
            }
            prev=colors[i];
            i=(i+1)%n;
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
