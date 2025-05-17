class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        for(int&i:arr)  i=A*pow(i,2)+B*i+C;
        sort(arr.begin(),arr.end());
        return arr;
    }
};
