class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        vector<string>ans;
        for(int i=0;i<pow(2,n);i++)
        {
            int k=i,b=1<<30;
            string str="";
            while(b)
            {
                if(b&k) str+="1";
                else    str+="0";
                b=b>>1;
            }
            str=str.substr(31-n);
            ans.push_back(str);
        }
        return ans;
    }
};
