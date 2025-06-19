class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string lower="",upper="";
        for(char&c:s)
        {
            if(65<=c && c<=90)  upper+=c;
            else                lower+=c;
        }
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        int i=0,j=0;
        for(char&c:s)
        {
            if(65<=c && c<=90)  c=upper[i++];
            else                c=lower[j++];
        }
        return s;
    }
};
