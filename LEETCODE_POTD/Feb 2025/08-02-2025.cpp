
// Problem -> https://leetcode.com/problems/design-a-number-container-system/?envType=daily-question&envId=2025-02-08

class NumberContainers {
    unordered_map<int,int>idx;
    unordered_map<int,set<int>>values;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idx[index])           values[idx[index]].erase(values[idx[index]].find(index));
        idx[index]=number;
        values[number].insert(index);
    }
    
    int find(int number) {
        if(values[number].empty()) return -1;
        return *values[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
