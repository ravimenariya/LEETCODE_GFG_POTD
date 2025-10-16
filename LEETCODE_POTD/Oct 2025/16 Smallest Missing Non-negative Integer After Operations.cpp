class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,bool>ump;
        vector<int>remainder(value,-1);
        for(int i:nums)
        {
            if(i<0)   i=(value-((0-i)%value))%value;
            else            i=i%value;
            if(remainder[i]!=-1)    remainder[i]+=value;
            else                    remainder[i]=i;
            ump[remainder[i]]=true;
        }
        int curr=0;
        while(ump[curr])    curr++;
        return curr;
    }
};
