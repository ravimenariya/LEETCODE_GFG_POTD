
// Problem -> https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        cost.push_back(0);
        int prev1=0,prev2=0,temp;
        for(int&i:cost)
        {
            temp=prev2;
            if(prev1<prev2)   prev2=prev1+i;
            else        prev2=prev2+i;
            prev1=temp;
        }
        return prev2;
    }
};
