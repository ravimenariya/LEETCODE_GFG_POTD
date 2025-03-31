class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int>end(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++)   end[s[i]-'a']=i;
        int ans=0;
        int st=0,ed=end[s[0]-'a'];
        for(int i=0;i<n;i++)
        {
            if(i==ed)
            {
                ans++;
                st=i+1;
                if(st<n)    ed=end[s[st]-'a'];
            }
            else    ed=max(ed,end[s[i]-'a']);
        }
        return ans;
    }
};
