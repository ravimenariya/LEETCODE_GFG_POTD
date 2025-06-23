class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        if(arr.size()%2!=0) arr.push_back(0);
        sort(arr.begin(),arr.end());
        string num1="",num2="";
        for(int i=0;i<arr.size();i+=2)
        {
            num1+=arr[i]+48;
            num2+=arr[i+1]+48;
        }
        
        string ans="";
        int i=num1.size()-1,carry=0;
        while(i>=0)
        {
            int sum=(num1[i]-48)+(num2[i]-48)+carry;
            carry=sum/10;
            ans+=(sum%10 + 48);
            i--;
        }
        if(carry)   ans+=(carry+48);
        
        while(ans.back()=='0')  ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
