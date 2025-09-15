class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        if(tar.size()>pat.size())   return false;
        int i=tar.size()-1,count=0,f=1;
        for(int j=pat.size()-1;j>=0;j--) 
        {
            if(pat[j]==tar[i]  && count%2==0)
            {
                i--;
                count=0;
                if(i==-1)    return true;
            }
            else  count++;
        }
        
        return false;
    }
};
