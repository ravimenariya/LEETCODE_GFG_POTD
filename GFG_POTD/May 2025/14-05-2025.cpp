class Solution {
  public:
    string countAndSay(int n) {
        // code here
         if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        string res = "";
        int i = 0;
        int j = 0;
        while (j < s.length())
        {
            if (s[j] == s[i])
                j++;
            else
            {
                res += to_string(j - i);
                res += s[i];
                i = j;
            }
        }

        res += to_string(j - i);
        res += s[i];
        return res;
    }
};
