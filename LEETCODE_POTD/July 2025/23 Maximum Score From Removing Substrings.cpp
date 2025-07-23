class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto solve = [](string s, char p1, char p2, int val) -> pair<string, int> {
            stack<char> stk;
            int score = 0;
            
            for (char c : s) {
                if (!stk.empty() && stk.top() == p1 && c == p2) {
                    stk.pop();
                    score += val;
                } else {
                    stk.push(c);
                }
            }

            string remaining = "";
            while (!stk.empty()) {
                remaining += stk.top();
                stk.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return {remaining, score};
        };

        if (x > y) {
            auto r1 = solve(s, 'a', 'b', x);
            auto r2 = solve(r1.first, 'b', 'a', y);
            return r1.second + r2.second;
        } else {
            auto r1 = solve(s, 'b', 'a', y);
            auto r2 = solve(r1.first, 'a', 'b', x);
            return r1.second + r2.second;
        }
    }
};
