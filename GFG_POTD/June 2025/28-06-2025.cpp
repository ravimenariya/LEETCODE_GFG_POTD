class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // Sort array b
        sort(b.begin(), b.end());
        
        vector<int> result;
        for (int num : a) {
          
            int count = upper_bound(b.begin(), b.end(), num) - b.begin();
            result.push_back(count);
        }
        
        return result;
    }
};
