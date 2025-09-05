class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int op = 1; op <= 60; op++) {
          long long remaining = num1 - ((long long)op * num2);
          if (remaining < op) return -1;
          if (op >= __builtin_popcountll(remaining)) return op;
        }
        return -1;
    }
};
