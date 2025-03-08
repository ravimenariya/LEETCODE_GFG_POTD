
// problem -> https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size(),l=0,r=0,w=0,ans=INT_MAX;
        while(r<k)  if(blocks[r++]=='W')  w++;
        if(ans>w)   ans=w;
        while(r<n)  
        {
            if(blocks[l++]=='W')  w--;
            if(blocks[r++]=='W')  w++;
            if(ans>w)   ans=w;
            if(!ans)    break;
        }
        return ans;
    }
};
