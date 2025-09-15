class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int i=0,n=text.size(),count=0;
        while(i<n)
        {
            if(brokenLetters.find(text[i])!=string::npos)
            {
                while(i<n && text[i]!=' ')  i++;
            }
            else if (text[i]==' ')  count++;
            i++;
        }
        if(i==n)    count++;
        return count;
    }
};
