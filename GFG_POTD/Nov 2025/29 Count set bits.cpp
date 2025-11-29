class Solution {
  public:
    int countSetBits(int n) {
        long long count = 0;
        for(long long bit = 1; bit <= n; bit <<= 1){
            long long fullCycles = (n + 1) / (bit << 1);
            count += fullCycles * bit;

            long long remainder = (n + 1) % (bit << 1);
            if(remainder > bit)
                count += remainder - bit;
        }
        return count;
    }
};
