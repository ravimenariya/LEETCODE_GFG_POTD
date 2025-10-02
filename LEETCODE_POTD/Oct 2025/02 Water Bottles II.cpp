class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0,empty=0;
        while(numBottles)
        {
            ans+=numBottles;
            empty+=numBottles;
            numBottles=0;
            while(empty>=numExchange)
            {
                numBottles++;
                empty-=numExchange;
                numExchange++;
            }
        }
        return ans;
    }
};
