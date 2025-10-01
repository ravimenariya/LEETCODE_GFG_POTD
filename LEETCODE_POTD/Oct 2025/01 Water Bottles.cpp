class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles/numExchange)
        {
            int t=numBottles;
            numBottles/=numExchange;
            ans+=numBottles;
            numBottles+=(t%numExchange);
        }
        return ans;
    }
};
