class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long curr=accumulate(arr.begin(),arr.end(),0),n=arr.size(),sum=((n+1)*(n+2))/2;
        return sum-curr;
    }
};
