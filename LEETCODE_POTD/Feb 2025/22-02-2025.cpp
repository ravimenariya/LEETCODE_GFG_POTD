
// problem -> https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/?envType=daily-question&envId=2025-02-22

class Solution {
    void solve(int&i,int&n,string&s,TreeNode* currnode,int currlevel,int&currnum,int&dashes,bool&st)
    {
        if(i>=n )   return;

        dashes=0;
        while(i<n && s[i]=='-')
        {
            dashes++;
            i++;
        }

        st=false;
        currnum=0;
        while(i<n && 48<=s[i] && s[i]<=57) 
        {
            currnum=currnum*10 + (s[i]-48);
            i++;
        }

        if((currlevel+1)==dashes )
        {
            TreeNode* temp=new TreeNode(currnum);
            currnode->left=temp;
            st=true;
            solve(i,n,s,temp,currlevel+1,currnum,dashes,st);
        }

        if(!st && (currlevel+1)==dashes )
        {
            TreeNode* temp=new TreeNode(currnum);
            currnode->right=temp;
            st=true;
            solve(i,n,s,temp,currlevel+1,currnum,dashes,st);
        }

    }
public:
    TreeNode* recoverFromPreorder(string s) {
        int i=0,num=0,n=s.size(),dashes=0,c=0;
        bool st=false;
        while(i<n && 48<=s[i] && s[i]<=57) 
        {
            num=num*10 + (s[i]-48);
            i++;
        }
        TreeNode* root=new TreeNode(num);
        solve(i,n,s,root,0,c,dashes,st);
        return root;
    }
};
