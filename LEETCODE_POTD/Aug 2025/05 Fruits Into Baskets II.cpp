class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;
        for(int i:fruits)
        {
            int f=1;
            for(int &j:baskets)
                if(j>=i) {
                    j=-1;
                    f=0;
                    break;
                }
            if(f)   ans++;
        }
        return ans;
    }
};
