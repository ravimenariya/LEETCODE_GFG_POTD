class Solution {
    string add(string s1,string s2)
    {
        int carry=0,n=s1.size(),m=s2.size(),a,b,c,sum,i;
        if(m>n)
        {
            swap(s1,s2);
            swap(n,m);
        }
        string ans;
        for(i=0;i<m;i++)
        {
            a=s1[n-i-1]-48,b=s2[m-i-1]-48,sum=a+b+carry,c=sum%10;
            ans=to_string(c)+ans;
            carry=sum/10;
        }
        while(i<n)
        {
            a=s1[n-i-1]-48,sum=a+carry,c=sum%10;
            ans=to_string(c)+ans;
            carry=sum/10;
            i++;
        }
        if(carry)   ans=to_string(carry)+ans;
        return ans;
    }
    bool solve(string&s,int&n,string a,string b,int i,int j)
    {;
        string c=add(a,b);
        int m=c.size();
        if((j+1+m)>n)   return false;
        string d=s.substr(j+1,m);
        if(c==d && ((j+1+m)==n || solve(s, n, b, c, j, j + m)))   return true;
        return false;
    }
  public:
    bool isSumString(string &s) {
        // code here
        int n=s.size();
        for(int i=0;i<(n/2);i++)
        {
            string a=s.substr(0,i+1);
            for(int j=i+1;j<=(n/2);j++)
            {
                string b=s.substr(i+1,j-(i+1)+1);
                if(solve(s,n,a,b,i,j))  return true;
            }
        }
        return false;
    }
};
