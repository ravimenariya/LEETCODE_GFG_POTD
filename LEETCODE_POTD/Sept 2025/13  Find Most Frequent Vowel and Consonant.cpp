class Solution {
public:
    int maxFreqSum(string s) {
        int vol=0,con=0;
        unordered_map<char,int>ump;
        for(char c:s)
            {
                ump[c]++;
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')   vol=max(vol,ump[c]);
                else con=max(con,ump[c]);
            }
        return vol+con;
    }
};
