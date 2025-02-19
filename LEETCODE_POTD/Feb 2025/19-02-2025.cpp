
// Problem -> https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2025-02-19

class Solution {
    string ans="";
    bool solve(vector<char>&v,int&n,int&k,string&str,int currsize,char prev)
    {
        if(currsize==n)
        {
            k--;
            if(!k)  
            {
                ans=str;
                return true;
            }
            return false;
        }
        for(char c:v)
        {
            if(c==prev) continue;
            str+=c;
            if(solve(v,n,k,str,currsize+1,c))   return true;
            str.pop_back();
        }
        return false;
    }
public:
    string getHappyString(int n, int k) {
        vector<char>v={'a','b','c'};  
        string str=""; 
        solve(v,n,k,str,0,'d'); 
        return ans;
    }
};
