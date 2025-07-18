class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        auto gcd = [](int x, int y) {
            while (y != 0) {
                int temp = y;
                y = x % y;
                x = temp;
            }
            return x;
        };
        
        auto lcm =[&](int a,int b,int c){
            int lcm_ab = (a * b) / gcd(a, b);
            int lcm_abc = (lcm_ab * c) / gcd(lcm_ab, c);
            return lcm_abc;
        };
        
        int ans=n;
        for(int i= max(1, n - 5);i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                {
                    int res=lcm(i,j,k);
                    ans=max(ans,res);
                }
        return ans;
    }
};
