
// problem -> https://leetcode.com/problems/find-missing-and-repeated-values/?envType=daily-question&envId=2025-03-06

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        n*=n;
        int sum=(n*(n+1))/2;
        unordered_map<int,bool>ump;
        int repeated,sum2=0;
        for(auto&v:grid)
            for(int&i:v)
                if(ump[i])  repeated=i;
                else
                {
                    ump[i]=true;
                    sum2+=i;
                }

        int missing =sum-sum2;
        vector<int>v;
        v.push_back(repeated);
        v.push_back(missing);
        return v;

    }
};
