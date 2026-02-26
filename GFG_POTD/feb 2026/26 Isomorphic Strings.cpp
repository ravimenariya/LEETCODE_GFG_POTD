class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        unordered_map<char,char>ump1,ump2;
        for(int i=0;i<s1.size();i++){
            if(ump1.find(s1[i])==ump1.end()){
                if(ump2.find(s2[i])!=ump2.end())    return false;
                ump1[s1[i]]=s2[i];
                ump2[s2[i]]=s1[i];
            }
            else if(s2[i]!=ump1[s1[i]] || s1[i]!=ump2[s2[i]]) return false;
        }
        
        
        return true;
    }
};
