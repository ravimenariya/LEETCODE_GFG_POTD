class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>prev_freq(26,0),next_freq(26,0);
        for(char c:s)   next_freq[c-'a']++;
        int ans=0;
        vector<vector<bool>>used(26,vector<bool>(26,false)); 
        // size of string is fixed to 3 that means there will be only 2 chars one with freq 1 and second with freq 2 like aba, xyx, so we will keep track that whether this combination of used[i] with freq 1 and used[i][j] with freq 2 is used or not
        for(char c:s)
        {
            next_freq[c-'a']--;
            for(int i=0;i<26;i++)   
            if(prev_freq[i] && next_freq[i] && !used[c-'a'][i]) 
            {
                ans++;
                used[c-'a'][i]=true;
            }
            prev_freq[c-'a']++;
        }
        return ans;
    }
};
