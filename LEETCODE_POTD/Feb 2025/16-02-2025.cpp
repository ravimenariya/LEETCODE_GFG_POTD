
// Problem -> https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/?envType=daily-question&envId=2025-02-16

class Solution {
    bool solve(int&n,int i,int&size,int&currsize,unordered_map<int,bool>&added,vector<int>&v)
    {
        if(currsize==size)  return true;
        if(i>=size) return false;
        if(v[i])
        {
            if(solve(n,i+1,size,currsize,added,v))    return true;
            return false;
        }
        for(int num=n;num>=1;num--)
        {
            if(!added[num])
            {
                if(num==1)
                {
                    v[i]=1;
                    currsize++;
                    added[num]=true;
                    if(solve(n,i+1,size,currsize,added,v))    return true;
                    v[i]=0;
                    currsize--;
                    added[num]=false;
                }
                else if((i+num)<size && v[i+num]==0)
                {
                    v[i]=num;
                    v[i+num]=num;
                    currsize+=2;
                    added[num]=true;
                    if(solve(n,i+1,size,currsize,added,v))    return true;
                    v[i]=0;
                    v[i+num]=0;
                    currsize-=2;
                    added[num]=false;
                }
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        int size=(n-1)*2+1,i=0,c=0;
        vector<int>ans(size,0);
        unordered_map<int,bool>added;

        solve(n,i,size,c,added,ans);
        return ans;
    }
};
