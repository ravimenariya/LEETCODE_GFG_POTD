
// Problem -> https://leetcode.com/problems/partition-labels/submissions/1590773160/?envType=daily-question&envId=2025-03-30

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>end(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++)   end[s[i]-'a']=i;
        vector<int>ans;
        int st=0,ed=end[s[0]-'a'];
        for(int i=0;i<n;i++)
        {
            if(i==ed)
            {
                ans.push_back(ed-st+1);
                st=i+1;
                if(st<n)    ed=end[s[st]-'a'];
            }
            else    ed=max(ed,end[s[i]-'a']);
        }
        return ans;
    }
};
