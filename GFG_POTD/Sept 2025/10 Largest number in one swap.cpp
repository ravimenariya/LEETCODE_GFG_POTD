class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.size(), mini=n-1,maxj=n-1,j=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<s[j])
            {
                mini=i;
                maxj=j;
            }
            if(s[i]>s[j])
            {
                j=i;
            }
        }
        swap(s[mini],s[maxj]);
        return s;
    }
};
