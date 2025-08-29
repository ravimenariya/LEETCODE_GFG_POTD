class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        unordered_map<char,int>smap,pmap,taken;
        for(char c:p)   pmap[c]++;
        int n=s.size(),m=p.size(),i=0,count=0,st=0,ans_st=-1,ans_size=INT_MAX;
        
        while(i<n){
            smap[s[i]]++;
            if(pmap[s[i]]>=smap[s[i]])      {
                taken[s[i]]++;
                count++;
            }
            while(smap[s[st]]>pmap[s[st]]){
                if(taken[s[st]]>=smap[s[st]])   {
                    taken[s[st]]--;
                    count--;
                }
                smap[s[st]]--;
                st++;
            }
            
            if(count==m){
                int size=i-st+1;
                if(size<ans_size){
                    ans_size=size;
                    ans_st=st;
                }
            }
            i++;
        }
        
        if(ans_st==-1)  return "";
        
        string ans="";
        for(int i=ans_st;i<(ans_st+ans_size);i++)   ans+=s[i];
        return ans;
    }
};
