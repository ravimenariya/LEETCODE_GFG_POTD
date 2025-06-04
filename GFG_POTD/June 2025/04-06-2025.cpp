class Solution {
public:
    int lcsOf3(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0));
        vector<vector<int>> curr(n2 + 1, vector<int>(n3 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                for (int k = 1; k <= n3; k++) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        curr[j][k] = 1 + prev[j - 1][k - 1];
                    } else {
                        curr[j][k] = max({prev[j][k], curr[j - 1][k], curr[j][k - 1]});
                    }
                }
            }

            // Copy curr to prev
            for (int j = 0; j <= n2; j++) {
                for (int k = 0; k <= n3; k++) {
                    prev[j][k] = curr[j][k];
                }
            }
        }

        return curr[n2][n3];
    }
};
