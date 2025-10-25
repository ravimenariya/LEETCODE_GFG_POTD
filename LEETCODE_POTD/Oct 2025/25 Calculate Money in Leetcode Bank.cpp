class Solution {
public:
    int totalMoney(int n) {
        int q=n/7,r=n%7;
        int t=q ? (q*28 + 7*(q*(q-1))/2) : 0;
        while(r--)  t+=(1+(q++));
        return t;
    }
};
