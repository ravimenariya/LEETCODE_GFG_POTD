class Solution {
public:
    int solve(int ind, string &s,
              vector<vector<int>> &adj,
              vector<long long> &pref,
              vector<vector<int>> &nextPos,
              vector<long long> &dp) {

        if (ind == (int)s.size() - 1) return 0;
        if (dp[ind] != -1) return dp[ind];

        long long best = 0;
        int curr = (unsigned char)s[ind];

        for (int target : adj[curr]) {

            int j = nextPos[ind][target];
            if (j == -1) continue;

            long long gain = pref[j] - pref[ind];

            for (int k = ind; k < j; k++)
                if ((unsigned char)s[k] == target)
                    gain -= target;

            gain += solve(j, s, adj, pref, nextPos, dp);
            best = max(best, gain);
        }
        return dp[ind] = best;
    }

    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();

        for (int c = 0; c < 256; c++)
            jumps.push_back({(char)c, (char)c});

        vector<vector<int>> nextPos(n, vector<int>(256, -1));
        vector<int> last(256, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 256; c++)
                nextPos[i][c] = last[c];
            last[(unsigned char)s[i]] = i;
        }

        vector<vector<int>> adj(256);
        for (auto &v : jumps)
            adj[(unsigned char)v[0]].push_back((unsigned char)v[1]);

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (unsigned char)s[i];

        vector<long long> dp(n, -1);
        return solve(0, s, adj, pref, nextPos, dp);
    }
};
