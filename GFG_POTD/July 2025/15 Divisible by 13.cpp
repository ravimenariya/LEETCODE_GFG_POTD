class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int num=0;
        for(char digit:s)    num=(num*10+(digit-48))%13;
        if(num) return false;
        return true;
    }
};
