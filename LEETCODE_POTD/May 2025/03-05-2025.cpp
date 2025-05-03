class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int s1 = 0, s2 = 0;
        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x)
                return INT_MAX;
            if (tops[i] != x) s1++;
            if (bottoms[i] != x) s2++;
        }
        return min(s1, s2);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int s = min(check(tops[0], tops, bottoms), 
                            check(bottoms[0], tops, bottoms));
        return s == INT_MAX ? -1 : s;
    }
};
