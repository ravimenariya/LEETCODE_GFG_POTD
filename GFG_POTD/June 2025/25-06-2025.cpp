class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int>freq(26,0);
        for(char c:s)   freq[c-'a']++;
        map<int,int>mp;
        for(int i:freq)
            if(i)    mp[i]++;

        if(mp.size()>2)    return false;
        if(mp.size()<2)    return true;
        auto it = mp.begin();    
        auto a = *it;
        ++it;                    
        auto b = *it;
        if (a.first == 1 && a.second == 1) return true;
        if (b.first == a.first + 1 && b.second == 1) return true;
        return false;
    }
};
