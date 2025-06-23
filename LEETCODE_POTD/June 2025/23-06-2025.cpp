class Solution {
    bool check(long long n,int k)
    {
        string num="";
        while(n){
            num+=((n%k)+48);
            n/=k;
        }
        int i=0,j=num.size()-1;
        while(i<j)
            if(num[i++]!=num[j--])  return false;
        return true;
    }

    void solve(int n,int&N,int k,long long &sum) 
    {
        long long start=pow(10,n/2-1), m=start*10;

        if(n%2==0)
            for (long long i = start; i < m; ++i) {
                string s = "";
                long long num=i;
                while(num)
                {
                    s+=((num%10)+48);
                    num/=10;
                }
                string rev = s;
                reverse(rev.begin(), rev.end());
                long long number=stoll(rev + s);
                if(!check(number,k))     continue;
                sum+=number;
                if(!(--N))  return;
            }
        else
            for (long long i = start; i < m; ++i) {
                string s = "";
                long long num=i;
                while(num)
                {
                    s+=((num%10)+48);
                    num/=10;
                }
                string rev = s;
                reverse(rev.begin(), rev.end());
                for (char mid = '0'; mid <= '9'; ++mid) {
                    long long number=stoll(rev +mid+ s);
                    if(!check(number,k))     continue;
                    sum+=number;
                    if(!(--N))  return;
                }
            }
        return ;
    }   
public:
    long long kMirror(int k, int n) {
        long long sum=0;
        vector<long long>pallindrome;
        for(int i=1;i<10;i++)   {
             if(!check(i,k))     continue;
            sum+=i;
            if(!(--n))  return sum;
        }

        for(int i=2;i<=11;i++)
        {
            solve(i,n,k,sum);
            if(!n)  break;
        }
        return sum;
    }   
};
