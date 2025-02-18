
// Problem -> https://leetcode.com/problems/construct-smallest-number-from-di-string/?envType=daily-question&envId=2025-02-18

class Solution {

    bool solve(string&pattern,int i,int&n,vector<bool>&v,string&ans,int prev)
    {
        if(i>=n)    return true;
        int d=pattern[i]=='I'?1:-1;
        for(int num=prev+d;1<=num && num<=9;num=num+d)
        if(!v[num])
        {
            v[num]=true;
            ans+=to_string(num);
            if(solve(pattern,i+1,n,v,ans,num))   return true;
            v[num]=false;
            ans.pop_back();
        }
        return false;        
    }

public:
    string smallestNumber(string pattern) {
        string ans="";
        int n=pattern.size();
        for(int i=1;i<=9;i++)
        {
            ans=to_string(i);
            vector<bool>v(10,false);
            v[i]=true;
            if(solve(pattern,0,n,v,ans,i))  break;
        }
        return ans;
    }
};
