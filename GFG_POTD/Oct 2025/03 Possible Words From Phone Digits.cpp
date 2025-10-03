class Solution {
    void solve(unordered_map<int,vector<char>>&ump, vector<int> &arr, int i, string str, vector<string>&ans )
    {
        if(i>=arr.size())
        {
            ans.push_back(str);
            return;
        }
        if(arr[i]==0 || arr[i]==1)  solve(ump,arr,i+1,str,ans);
        else {
        for(char c:ump[arr[i]])
        {
            str+=c;
            solve(ump,arr,i+1,str,ans);
            str.pop_back();
        }
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        unordered_map<int,vector<char>>ump;
        int i=2;
        char c='a';
        while(i<=9)
        {
            int n=3;
            if(i==7 || i==9)    n=4;
            while(n--)
            {
                ump[i].push_back(c);
                c++;
            }
            i++;
        }
        vector<string>ans;
        solve(ump,arr,0,"",ans);
        return ans;
    }
};
