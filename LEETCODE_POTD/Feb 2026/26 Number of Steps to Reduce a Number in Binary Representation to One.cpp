class Solution {
    void add(string& s, int&i) {
        int carry = 0,p=i;
        do {
            if (s[p] == '1') {
                carry = 1;
                s[p] = '0';
            } else {
                carry = 0;
                s[p] = '1';
            }
            p--;
        } while (p>=0 && carry);

        if(carry)   {
            s="1"+s;
            i++;
        }
    }

public:
    int numSteps(string s) {
        int i = s.size() - 1, steps = 0;

        while (i > 0) {
            if (s[i] == '1') {
                add(s, i);
                steps++;
            }
            steps++;
            i--;
        }
        return steps;
    }
};
