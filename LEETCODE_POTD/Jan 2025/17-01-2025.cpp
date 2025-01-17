class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int k=1,prev=1,n=derived.size();
        for(int i=0;i<n-1;i++)          prev^=derived[i];
        if(k^prev==derived[n-1])  return true;
        k=0,prev=0;
        for(int i=0;i<n-1;i++)          prev^=derived[i];
        if(k^prev==derived[n-1])  return true;
        return false;
    }
};
