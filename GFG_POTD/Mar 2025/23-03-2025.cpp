
// Problem -> https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

class Solution {
  public:
    int countWays(string &digits) {
        // Code here
        if(!(digits[0]-48)) return 0;
        int sig=1,p=0,n;
        for(int i=1;i<digits.size();i++)
        {
            n=(digits[i-1]-48)*10+digits[i]-48;
            if(n<=26)
            {
                if(!(digits[i]-48))
                {
                    p=sig;
                    sig=0;
                }
                else{
                n=sig;
                sig+=p;
                p=n;
                }
            }
            else 
            {
                if(!(digits[i]-48)) return 0;
                sig+=p;
                p=0;
            }
        }
        return sig+p;
    }
};
