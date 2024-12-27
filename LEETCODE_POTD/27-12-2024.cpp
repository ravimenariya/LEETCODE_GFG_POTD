class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>v(n);
        v[n-1]=INT_MIN;
        for(int j=n-2;j>=0;j--)        v[j]=max(v[j+1],values[j+1]-j-1);
        int m=INT_MIN;
        for(int i=0;i<n-1;i++)          m=max(m,values[i]+i+v[i]);
        return m;
    }
};
