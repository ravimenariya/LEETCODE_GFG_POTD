class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        int currnum=1,m=queries.size(),mod=1e9 + 7;
        while(n){
            if(n&1) powers.push_back(currnum);
            currnum*=2;
            n=n>>1;
        }
        vector<int>ans(m,1);
        for(int i=0;i<m;i++){
            for(int j=queries[i][0];j<=queries[i][1];j++)
                ans[i]=((long long)ans[i]*powers[j])%mod;
        }
        return ans;
    }
};
