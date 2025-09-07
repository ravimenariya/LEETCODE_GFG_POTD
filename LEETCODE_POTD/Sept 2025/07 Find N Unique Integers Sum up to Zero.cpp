class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2 && n--) ans.push_back(0);
        int i=1;
        while(n)
        {
            ans.push_back(i);
            ans.push_back(i*(-1));
            n-=2;
            i++;
        }
        return ans;
    }
};
