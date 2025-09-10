class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto check=[](int n){
            while(n){
                if(!(n%10)) return false;
                n/=10;
            }
            return true;
        };

        int a,b;
        for(a=1;a<n;a++){
            b=n-a;
            if(check(a) && check(b))    break;
        }
        return {a,b};
    }
};
