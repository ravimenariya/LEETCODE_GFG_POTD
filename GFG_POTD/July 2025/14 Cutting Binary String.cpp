class Solution {
    int ans=-1;
    bool solve(string&s,int st,int count)
    {
        if(st<0)    {
            ans=count;
            return true;
        }
        int num=0,f=1;
        for(int i=st;i>=0;i--)  if(s[i]=='1')  num+=(1<<(st-i));
        for(int i=0;i<=st;i++)
        {
            if(s[i]=='0')       continue;
            if(check(num) && solve(s,i-1,count+1))  return true;
            num-=1<<(st-i);
        }
        return false;
    }
    bool check(int n)
    {
        while( n%5==0)  n/=5;
        if(n==1)      return true;
        return false;
    }
  public:
    int cuts(string s) {
        // code here
        solve(s,s.size()-1,0);
        return ans;
    }
};
