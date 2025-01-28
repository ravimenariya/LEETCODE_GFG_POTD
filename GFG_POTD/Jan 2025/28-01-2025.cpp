
// problem -> https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution {
    void backtrack(string &s, vector<bool> &used, string &current, set<string> &result) {
    if (current.size() == s.size()) {
        result.insert(current); 
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue; 
        
        used[i] = true;       
        current.push_back(s[i]); 
        backtrack(s, used, current, result);
        current.pop_back();   
        used[i] = false;      
    }
}
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> permutations;
        set<string> result;      
    vector<bool> used(s.size(), false);
    string current = "";
    
    sort(s.begin(), s.end()); 
    backtrack(s, used, current, result);

    permutations.assign(result.begin(), result.end());
    return permutations;
    }
};
