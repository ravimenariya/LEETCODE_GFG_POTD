class Solution {
public:
    int possibleStringCount(string word) {
        int extra=0,i=0,n=word.size();
        while(i<n)
        {
            while((i+1)<n && word[i+1]==word[i])
            {
                extra++;
                i++;
            }
            i++;
        }
        return extra+1;
    }
};
