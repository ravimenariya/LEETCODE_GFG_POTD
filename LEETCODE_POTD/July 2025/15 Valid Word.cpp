class Solution {
    bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')  return true;
        return false;
    }
public:
    bool isValid(string word) {
        if(word.size()<3)   return false;
        int cons=1,vow=1;
        for(char c:word){
            if(isalpha(c)){
                if(check(tolower(c)))    vow=0;
                else                     cons=0;
            }
            else if(!isdigit(c))    return false;
        }
        if(cons || vow) return false;
        return true;
    }
};
