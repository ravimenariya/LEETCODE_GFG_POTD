class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(),dominoes.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]>a[1])   swap(a[0],a[1]);
            if(b[0]>b[1])   swap(b[0],b[1]);
            
            if(a[0]==b[0])  return a[1]<b[1];
            return a[0]<b[0];
        });

        int ans=0,st=0,n=dominoes.size(),m;

        for(int i=1;i<n;i++)
            if(dominoes[st][0]!=dominoes[i][0] || dominoes[st][1]!=dominoes[i][1])
            {
                m=i-st;
                ans+=((m*(m-1))/2);
                st=i;
            }
        m=n-st;
        ans+=((m*(m-1))/2);
        return ans;
    }
};
