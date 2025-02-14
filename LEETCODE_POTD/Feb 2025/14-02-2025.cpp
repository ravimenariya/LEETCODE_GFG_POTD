
// Problem ->  https://leetcode.com/problems/product-of-the-last-k-numbers/?envType=daily-question&envId=2025-02-14

class ProductOfNumbers {
    vector<int>v={1};
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if(num)
        v.push_back(v.back()*num);
        else
        {
            v.clear();
            v.push_back(1);
        }
    }
    
    int getProduct(int k) {
        return v.size()>k?v.back()/v[v.size()-1-k]:0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
