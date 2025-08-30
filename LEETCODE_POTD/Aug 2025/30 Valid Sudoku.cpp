class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;

        for(int i=0;i<9;i++)
        {
            st.clear();   
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' && st.find(board[i][j])!=st.end())  return false;
                st.insert(board[i][j]);
            }
        }

         for(int i=0;i<9;i++)
        {
            st.clear();   
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.' &&st.find(board[j][i])!=st.end())  return false;
                st.insert(board[j][i]);
            }
        }

        int p1=0,p2=0;
        for(int i=0;i<9;i++)
        {
            st.clear();
            for(int j=p1;j<(p1+3);j++)
            {
                for(int k=p2;k<(p2+3);k++)
                {
                    if(board[j][k]!='.' &&st.find(board[j][k])!=st.end())  return false;
                st.insert(board[j][k]);
                }
            }
            if(p2>=6)   {p1+=3;p2=0;}
            else        p2+=3;
        }

        return true;
    }
};
