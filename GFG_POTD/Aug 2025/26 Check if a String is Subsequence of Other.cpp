class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n=s1.size(),i=0;
        for(char c:s2){
            if(c==s1[i])    i++;
            if(i==n)    return true;
        }
        return false;
    }
};
