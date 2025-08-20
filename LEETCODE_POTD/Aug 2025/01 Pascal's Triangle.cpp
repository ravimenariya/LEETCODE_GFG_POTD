class Solution {
    vector<int>solve(int n)
    {
        vector<int>v(1,1);
        int res=1;
        for(int col=1;col<n;col++)
        {
            res=res*(n-col);
            res=res/col;
            v.push_back(res);
        }
        return v;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int n=1;n<=numRows;n++)
            ans.push_back(solve(n));
        return ans;
    }
};
