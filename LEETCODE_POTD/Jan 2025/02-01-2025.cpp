class Solution {
private:
    int check(string &s)
    {
        char a=s[0],b=s[s.size()-1];
        if((a=='a' || a=='e' || a=='i' || a=='o' || a=='u')&&(b=='a' || b=='e' || b=='i' || b=='o' || b=='u'))  
        return 1;
        return 0;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++)           v[i]=v[i-1]+check(words[i-1]);
        vector<int>ans;
        for(auto&i:queries)             ans.push_back(v[i[1]+1]-v[i[0]]);
        return ans;
    }
};
