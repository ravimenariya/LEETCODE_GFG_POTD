class Solution {
  public:
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        
        fun(s, temp, ans);
        return ans;
    }
       bool isPalin(string s){
        int l = 0;
        int r = s.size()-1;
        
        while(l<r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void fun(string s, vector<string> &temp, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=1;i<=(s.size());i++){
            string p = s.substr(0, i);
            if(isPalin(p)){
                temp.push_back(p);
                fun(s.substr(i), temp, ans);
                temp.pop_back();
            }
        }    
        return;
    }
};
