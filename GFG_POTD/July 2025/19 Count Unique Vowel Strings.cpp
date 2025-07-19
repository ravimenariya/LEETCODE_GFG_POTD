class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        vector<int>fact={1,2,6,24,120};
        unordered_map<char,int>ump;
        for(char c:s)   
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')  ump[c]++;
        
        int ans=fact[ump.size()-1];
        for(auto i:ump)     ans*=i.second;
        return ans;
    }
};
