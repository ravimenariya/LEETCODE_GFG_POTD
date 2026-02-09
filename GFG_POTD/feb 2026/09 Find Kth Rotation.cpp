class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        for(int i=1;i<arr.size();i++)
            if(arr[i]<arr[i-1])
                return i;
        return 0;
    }
};
