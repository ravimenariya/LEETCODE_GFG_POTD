class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>a,vector<int>b){
            if(a[0]==b[0])  return a[1]>b[1];
            return a[0]<b[0];
        });
        int count=0;
        for(int i=1;i<points.size();i++)
        {
            int j=i-1;
            while(j>=0 )  
            {
                if(points[j][0]>points[i][0] || points[j][1]<points[i][1]){
                    j--;
                    continue;
                }
                int f=1;
                for(int k=j+1;k<i;k++)
                {
                    if(points[j][0]<=points[k][0] && points[k][0]<=points[i][0] &&
                     points[i][1]<=points[k][1] && points[k][1]<=points[j][1] )
                     {
                        f=0;
                        break;
                     }
                }
                if(f)   count++;
                j--;
            }
        }
        return count;
    }
};
