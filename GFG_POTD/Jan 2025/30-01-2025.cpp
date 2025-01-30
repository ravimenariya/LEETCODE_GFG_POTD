
// problem -> https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

class Solution
{
public:
    bool check(int n, int x, int y, vector<string> &mat)
    {
        // for row check
        for (int i = 0; i < n; i++)
            if (mat[x][i] == 'Q')
                return 0;

        // for column check
        for (int i = 0; i < n; i++)
            if (mat[i][y] == 'Q')
                return 0;

        // for diagonal 1
        int i = x - min(x, y);
        int j = y - min(x, y);
        while (i < n && j < n)
        {
            if (mat[i][j] == 'Q')
                return 0;
            i++;
            j++;
        }

        // for diagonal 2
        i = x - 1;
        j = y + 1;
        while (i >= 0 && j < n)
        {
            if (mat[i][j] == 'Q')
                return 0;
            i--;
            j++;
        }
        i = x + 1;
        j = y - 1;
        while (i < n && j >= 0)
        {
            if (mat[i][j] == 'Q')
                return 0;
            i++;
            j--;
        }

        return 1;
    }

    void solve(int n, int x, int queens, vector<string> mat, vector<vector<string>> &ans)
    {

        if (queens == n)
        {
            ans.push_back(mat);
            return;
        }

        if (x >= n)
            return;

        for (int i = 0; i < n; i++)
        {
            if (check(n, x, i, mat))
            {
                mat[x][i] = 'Q';

                solve(n, x + 1, queens + 1, mat, ans);
                mat[x][i] = '.';
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<vector<string>> ans;
        string s;
        for (int i = 0; i < n; i++)
        {
            s += ".";
        }
        vector<string> mat(n, s);
        int queens = 0;

        solve(n, 0, queens, mat, ans);

        vector<vector<int>> res;
        
        
        for(int i=0;i<ans.size();i++)
        {
        vector<int> v(n);
            for(int j=0;j<ans[i].size();j++)
            {
                
                for(int k=0;k<ans[i][j].size();k++)
                {
                    if(ans[i][j][k]=='Q')
                    {
                        v[j]=k+1;
                        break;
                    }
                }
            }
            res.push_back(v);
        }
        
        return res;
    }
};
