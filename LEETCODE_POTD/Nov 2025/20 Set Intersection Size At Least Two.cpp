class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto&a,auto&b){if(a[1]==b[1])    return a[0]>b[0]; return a[1]<b[1];});

        int a=-1,b=-1,n=0;
        for(int i=0;i<intervals.size();i++)
        {
            if(b<intervals[i][0])
            {
                a=intervals[i][1]-1;
                b=intervals[i][1];
                n+=2;
            }
            else if(a<intervals[i][0])
            {
                a=b;
                b=intervals[i][1];
                n++;
            }
        }
        return n;
    }
};
