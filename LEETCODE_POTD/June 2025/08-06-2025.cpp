class Solution {
    void solve(int k,vector<int>&ans,int&n)
    {
        ans.push_back(k);
        if(k*10<=n)         solve(k*10,ans,n);
        
        for(int i=1;(k+i)%10!=0;i++)
        {
            if((k+i)>n) return;
            ans.push_back(k+i); 
            if((k+i)*10<=n)         solve((k+i)*10,ans,n);    
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        solve(1,ans,n);
        return ans;
    }
};
