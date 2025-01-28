
//   problem -> https://leetcode.com/problems/course-schedule-iv/?envType=daily-question&envId=2025-01-27

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize a reachability matrix
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // Step 2: Populate direct prerequisites
        for (auto& p : prerequisites) {
            reachable[p[0]][p[1]] = true;
        }

        // Step 3: Compute transitive closure using Floyd-Warshall
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }

        // Step 4: Answer the queries
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(reachable[q[0]][q[1]]);
        }

        return ans;
    }
};
