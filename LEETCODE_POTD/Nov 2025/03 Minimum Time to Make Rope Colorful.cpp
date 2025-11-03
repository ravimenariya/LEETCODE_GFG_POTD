class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int min_time=0,n=colors.size(),i=1;
        while(i<n)
        {
            if(colors[i]==colors[i-1])
            {
                int mt=neededTime[i-1],total=mt;
                while(i<n && colors[i]==colors[i-1])
                {
                    mt=max(mt,neededTime[i]);
                    total+=neededTime[i];
                    i++;
                }
                min_time+=(total-mt);
            }
            else i++;
        }
        return min_time;
    }
};
