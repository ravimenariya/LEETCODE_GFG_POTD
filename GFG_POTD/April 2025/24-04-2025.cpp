class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        unordered_map<int,int>ump;
        for(int&i:arr)  ump[i]++;
        for(auto&i:ump) if(i.second==1) return i.first;
        return 1;
    }
};
