
// Problem -> https://leetcode.com/problems/find-the-punishment-number-of-an-integer/?envType=daily-question&envId=2025-02-15

class Solution {
    bool check(int&num,string&str,int& digit,int i,vector<int>&v)
    {
        if(i==digit)
        {
            int sum=accumulate(v.begin(),v.end(),0);
            if(sum==num)    return true;
            return false;
        }
        int j=1;
        while(j<=4 && (i+j)<=digit)
        {
            string part=str.substr(i,j);
            int n=stoi(part);
            v.push_back(n);
            if(check(num,str,digit,i+j,v))  return true;
            v.pop_back();
            j++;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        if(n<9) return 1;
        int ans=1;
        for(int num=9;num<=n;num++)
        {
            int sqr=num*num;
            string str=to_string(sqr);
            vector<int>v;
            int digit=str.size();
            if(check(num,str,digit,0,v))    ans+=sqr;
        }
        return ans;
    }
};
