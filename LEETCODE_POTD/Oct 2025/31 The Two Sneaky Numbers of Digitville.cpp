class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,bool>ump;
        vector<int>ans;
        for(int i:nums)
        {
            if(ump[i]){
                ans.push_back(i);
                if(ans.size()==2)   break;
            }
            ump[i]=true;
        }
        return ans;
    }
};
