class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false;
        
        unordered_map<int, int> used;
        stack<int> open, unlock;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                unlock.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else {
                if (!open.empty()) {
                    used[open.top()] = 1;
                    open.pop();
                } else if (!unlock.empty()) {
                    used[unlock.top()] = 1;
                    unlock.pop();
                } else {
                    return false;
                }
            }
        }

        while (!open.empty()) {
            if (unlock.empty()) return false;
            if (unlock.top() < open.top()) return false;
            used[unlock.top()] = 1;
            unlock.pop();
            open.pop();
        }

        int remaining = unlock.size();
        return remaining % 2 == 0;
    }
};
