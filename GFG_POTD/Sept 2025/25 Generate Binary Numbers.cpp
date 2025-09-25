class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        auto getBinary=[](int n){
            int k=1<<30;
            string str="";
            while(k>0)
            {
                if(n&k) str+="1";
                else if(str!="")    str+="0";
                k=k>>1;
            }
            return str;
        };
        
        vector<string>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(getBinary(i));
        }
        return ans;
    }
};
