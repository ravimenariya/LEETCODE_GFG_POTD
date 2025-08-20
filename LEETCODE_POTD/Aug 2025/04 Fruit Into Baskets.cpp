class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>ump;
        int unique=0,maxSize=0,l=0,r=0,n=fruits.size();
        while(r<n)
        {
            if(!ump[fruits[r]]) unique++;
            ump[fruits[r]]++;
            while(unique>2)
                if(--ump[fruits[l++]]==0)   unique--;
            maxSize=max(maxSize,r-l+1);
            r++;
        }
        return maxSize;
    }
};
