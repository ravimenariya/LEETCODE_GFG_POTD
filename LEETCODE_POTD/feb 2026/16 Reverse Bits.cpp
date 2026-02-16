class Solution {
public:
    int reverseBits(int n) {
        int ans=0,p1=2,p2=1<<30,c=31;
        // the reason behind this is when we start p2 from 1<<31 then we get negative value (INT_MIN) so on doing right shift p2>>1 it becomes 1100(30 zeros) which cause problems
        // the logic of starting p1 from p2 is, n is always even so LSB of ans will be 0 always
        while(c--){
            if(n&p1){
                ans=ans|p2;
            }
            p1=p1<<1;
            p2=p2>>1;
        }
        return ans;
    }
};
