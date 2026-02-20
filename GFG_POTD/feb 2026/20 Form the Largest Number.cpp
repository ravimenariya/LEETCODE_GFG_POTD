class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string>str;
        for(int i:arr)  str.push_back(to_string(i));
        
        sort(str.begin(),str.end(),[](string s1,string s2){
            return s1+s2 > s2+s1;
        });
        
        if(str[0]=="0") return "0";
        
        string ans="";
        for(string s:str)   ans+=s;
        
        return ans;
    }
};
