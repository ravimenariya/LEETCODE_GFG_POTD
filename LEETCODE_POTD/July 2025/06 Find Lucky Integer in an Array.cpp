class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>ump;
        for(int i:arr)  ump[i]++;
        int ans=-1;
        for(auto i:ump) 
            if(i.first==i.second && i.first>ans)  ans=i.first;
        return ans;
    }
};
