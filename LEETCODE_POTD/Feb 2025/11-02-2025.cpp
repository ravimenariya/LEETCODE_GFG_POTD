
// problem -> https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string prev="";
        int n=s.size(),k=part.size();
        if(n<k) return s;
        for(int i=0;i<k;i++)    prev+=s[i];
        for(int i=k;i<n;i++)
        {
            if(prev.size()>=k)
            {
                string temp=prev.substr(prev.size()-k);
                if(temp==part)
                {
                    if(prev.size()==k)prev="";
                else
                prev=prev.substr(0,prev.size()-k);
                }
            }
            prev+=s[i];
        }
         if(prev.size()>=k)
            {
                string temp=prev.substr(prev.size()-k);
                if(temp==part)
                {
                    if(prev.size()==k)prev="";
                else
                prev=prev.substr(0,prev.size()-k);
                }
            }
        return prev;

    }
};
