
// Problem -> https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

class Solution {
  public:
    string longestPalindrome(string S) {
        int n=S.size();
        int start=0,max_len=1;
        int left,right;
        
        for(int i=0;i<n;i++)
        {
            left=i-1;
            right=i;
            
            while(left>=0 && right<n && S[left]==S[right])
            {
                if(right-left+1>max_len)
                {
                    max_len=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
            
            left=i-1;
            right=i+1;
            
            while(left>=0 && right<n && S[left]==S[right])
            {
                if(right-left+1>max_len)
                {
                    max_len=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
        }
        
        string str;
        for(int i=start;i<start+max_len;i++)
            str+=S[i];
            
        return str;
    }
};
