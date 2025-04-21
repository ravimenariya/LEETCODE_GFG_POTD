class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int minV = 0,maxV = 0,a = 0;
        for(int i=0; i < d.size(); i++){
            a += d[i];
            maxV = max(maxV, a);
            minV = min(minV, a); 
            if(((upper - maxV) - (lower - minV) + 1 < 0)) return 0;
        }
        return (upper - maxV) - (lower - minV) + 1;
    }
};
