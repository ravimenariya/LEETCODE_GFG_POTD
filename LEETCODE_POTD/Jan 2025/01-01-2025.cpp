class Solution
{
public:
    int maxScore(string s)
    {
        int left = s[0] == '0' ? 1 : 0;
        int right = 0;
        for (int i = 1; i < s.length(); i++)
        {
            right += (s[i] == '1') ? 1 : 0;
        }
        int maxsum = left + right;
        for (int j = 1; j < s.length() - 1; j++)
        {
            if (s[j] == '0')
                left += 1;
            else
                right -= 1;
            maxsum = max(maxsum, left + right);
        }
        return maxsum;
    }
};
