class Solution {
  public:
    int countPS(string &S) {
        // code here
        int c=0,n=S.size();
        int left,right;
        
        for(int i=0;i<n;i++)
        {
            left=i-1;
            right=i;
            
            while(left>=0 && right<n && S[left]==S[right])
            {
                c++;
                left--;
                right++;
            }
            
            left=i-1;
            right=i+1;
            
            while(left>=0 && right<n && S[left]==S[right])
            {
                c++;
                left--;
                right++;
            }
        }
        
        return c;
    }
};

