class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        multiset<int> st(begin(workers), begin(workers) + mid); // Select top 'mid' workers

        for (int i = mid - 1; i >= 0; i--) {
            int required = tasks[i];
            auto it = prev(st.end()); // Strongest available worker

            if (*it >= required) {
                st.erase(it);
            } else if (pillsUsed >= pills) {
                return false;
            } else {
                // Use a pill to help the weakest worker who can now do this task
                auto weakest = st.lower_bound(required - strength);
                if (weakest == st.end()) return false;
                st.erase(weakest);
                pillsUsed++;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();
        int l = 0, r = min(m, n), result = 0;

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(tasks, workers, pills, strength, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
