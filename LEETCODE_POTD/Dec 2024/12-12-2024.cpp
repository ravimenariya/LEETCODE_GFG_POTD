// 2558_Take_Gifts_From_the_Richest_Pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int&i:gifts)       pq.push(i);
        while(k--)
        {
            int t=pq.top();
            pq.pop();
            t=sqrt(t);
            pq.push(t);
        }
        long long sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
