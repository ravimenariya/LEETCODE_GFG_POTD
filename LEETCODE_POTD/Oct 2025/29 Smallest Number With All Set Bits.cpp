class Solution {
public:
    int smallestNumber(int n) {
        int ans=1,i=1<<30;
        while(i)
        {
            if(n&i) break;
            i=i>>1;
        }
        i=i<<1;
        return i-1;
    }
};
