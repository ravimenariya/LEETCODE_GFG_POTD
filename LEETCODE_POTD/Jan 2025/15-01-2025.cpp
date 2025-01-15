class Solution {
    int countset(int n)
    {
        int set=0;
        while(n)
        {
            if(n&1) set++;
            n=n>>1;
        }
        return set;
    }
public:
    int minimizeXor(int num1, int num2) {
        int num1bits=countset(num1);
        int num2bits=countset(num2);
        int ans=num1,i=0,k=abs(num1bits-num2bits),t;

        if(num1bits==num2bits)  return num1;
        else if(num1bits<num2bits)
        {
            while(k)
            {
                t=1<<i;
                if(!(ans&t))
                {
                    ans |=t;
                    k--;
                }
                i++;
            }
            return ans;
        }
        else
        {
            while(k)
            {
                t=1<<i;
                if(ans&t)
                {
                    ans &=~t;
                    k--;
                }
                i++;
            }
            return ans;
        }
    }
};
