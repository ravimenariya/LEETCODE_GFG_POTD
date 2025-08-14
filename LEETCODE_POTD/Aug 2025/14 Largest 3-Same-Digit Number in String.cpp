class Solution {
public:
    string largestGoodInteger(string num) {
        char j=47;
        for(int i=2;i<num.size();i++)
            if(num[i]==num[i-1] && num[i]==num[i-2] && num[i]>j)  
                j=num[i];
        string ans(3,j);
        if(j==47)   return "";
        return ans;
    }
};
