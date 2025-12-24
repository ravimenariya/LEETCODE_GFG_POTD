class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=accumulate(apple.begin(),apple.end(),0),count=0;
        sort(capacity.begin(),capacity.end());
        for(int i=capacity.size()-1;i>=0 && total>0;i--){
            total-=capacity[i];
            count++;
        }
        return count;
    }
};
