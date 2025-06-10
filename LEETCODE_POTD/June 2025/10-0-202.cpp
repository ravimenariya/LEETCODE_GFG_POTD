class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        int modd=0,meven=INT_MAX;
        for(char&c:s)           freq[c-'a']++;
        for(auto&i:freq)
            if(!i)  continue;
            else if(i%2!=0 && modd<i)    modd=i;
            else if(i%2==0 && meven>i)   meven=i;
        return modd-meven;
    }
};
