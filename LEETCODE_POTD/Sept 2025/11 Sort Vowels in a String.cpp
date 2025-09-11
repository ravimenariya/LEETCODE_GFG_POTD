class Solution {
public:
    string sortVowels(string s) {
        auto check = [](char c){
            return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') ? true : false;
        };

        map<int,int>mp;
        for(char c:s)   
            if(check(c))    mp[c]++;
        
        for(char&c:s)
        {
            if(check(c))
            {
                auto it=mp.begin();
                c=(*it).first;
                (*it).second--;
                if(!(*it).second)   mp.erase(it);
            }
        }

        return s;
    }
};
