class Solution {
public:
    bool checkOnesSegment(string s) {
        bool have_zero = false;
        for(char c:s){
            if(c=='1' && have_zero) return false;
            if(c=='0')  have_zero=true;
        }
        return true;
    }
};
