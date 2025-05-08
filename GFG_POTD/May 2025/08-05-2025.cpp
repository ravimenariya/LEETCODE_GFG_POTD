class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int a=-1,b=-1,sta,stb,d,n=arr.size();
        for(int i=1;i<n;i++)
        {
            d=arr[i]-arr[i-1];
            if(d!=a && d!=b)
            {
                if(a==-1)
                {
                    a=d;
                    sta=arr[i-1];
                }
                else
                {
                    b=d;
                    stb=arr[i-1];
                    break;
                }
            }
        }
        if(b==-1)   return  arr[n-1]+a;
        
        if(a>b)     return sta + b;
        
        return stb+a;
    }
};
