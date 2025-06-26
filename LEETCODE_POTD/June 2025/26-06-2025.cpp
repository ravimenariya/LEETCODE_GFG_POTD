class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size(),prev_z=0;

        auto check = [n,k, &s](int start) -> bool {
            int j = n - 1;
            unsigned long long num = 0;
            int i = 0;
            while (j >= start) {
                if (s[j] == '1') num += (1ULL << i);
                if (i >= 31) return false; 
                if (num > k) break;
                i++;
                j--;
            }
            return num && num <= k;
        };

        for(int i=0;i<n;i++)
        {
            if(s[i]!='1')   
            {
                prev_z++;
                continue;
            }
            if(check(i))  return prev_z+n-i;
        }
        return prev_z;
    }
};
