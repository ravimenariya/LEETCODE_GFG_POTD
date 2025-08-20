class Solution {
public:
    vector<int>segTree; 
    void build(int i , int l, int r , vector<int> &baskets){
        if(l==r){
            segTree[i] = baskets[l];
            return ; 
        }

        int mid = l + (r- l) /2; 
        build(2*i+1, l , mid , baskets);
        build(2*i+2, mid + 1, r , baskets);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }

    bool segQuery(int i , int l , int r , int &fruit , vector<int> &baskets){
        if(segTree[i]  < fruit)          return false; 
        if(l==r){
            segTree[i] = -1; 
            return true; 
        }

        int mid = l + (r-l)/2; 
        bool placed = false; 
        if(segTree[2*i+1] >= fruit)       placed = segQuery(2*i+1, l , mid , fruit , baskets);
        else            placed = segQuery(2*i +2, mid + 1, r, fruit , baskets);
        
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        return placed; 
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree.resize(4*n, -1);

        build(0, 0 , n-1 , baskets);
        int unplaced = 0; 
        for(auto &fruit : fruits)
          if(!segQuery(0, 0, n-1 , fruit, baskets))          unplaced++;
        
      return unplaced; 
    }
};
