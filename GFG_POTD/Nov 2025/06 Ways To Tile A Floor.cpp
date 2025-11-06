class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        if(n==1)    return 1;
        if(n==2)    return 2;
        int a=1,b=2;
        n-=2;
        while(n--)
        {
            b=a+b;
            a=b-a;
        }
        return b;
    }
};
