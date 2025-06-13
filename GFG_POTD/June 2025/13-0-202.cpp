class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int l = 1, r = *max_element(arr.begin(), arr.end()), ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2, h = 0;
            for (int i : arr)     h += ceil((double)i / m);
            if (h <= k) {
                ans = m;     
                r = m - 1;   
            } 
            else    l = m + 1;   
        }
        return ans;
    }
};
