class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>ump;
        for(int&i:answers)  ump[i]++;
        int ans=0;
        for(auto&i:ump)
        {
            int r=(i.first + 1)*(i.second/(i.first+1));
            ans+=r;
            if(i.second>r)
            ans+=(i.first+1);
        }
        return ans;
    }
};
