class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int sqr=i*i + j*j;
                float rt=sqrt(sqr);
                if(rt<=n && rt==(int)rt)       count++;
            }
        }
        return count;
    }
};
