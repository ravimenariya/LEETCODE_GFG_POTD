
// Problem -> https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int p1=0,p2=0,temp;
        for(int&i:arr)
        {
            temp=p1;
            p1=max(p1,p2+i);
            p2=temp;
        }
        return max(p1,p2);
    }
};
