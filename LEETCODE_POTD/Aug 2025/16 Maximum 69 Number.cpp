class Solution {
public:
    int maximum69Number (int num) {
        int n=0,fliped=0;
        while(num)
        {
            n=n*10+num%10;
            num/=10;
        }
        while(n)
        {
            if(!fliped && n%10==6)  {
                num=num*10+9;
                fliped=1;
            }
            else    num=num*10+n%10;
            n/=10;
        }
        return num;
    }
};
