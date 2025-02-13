
// problem -> https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/?envType=daily-question&envId=2025-02-13

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int &i:nums)    pq.push(i);
        int steps=0;
        while(pq.size()>=2)
        {
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            if(a>=k && b>=k)    break;
            steps++;
            long long t=a;
            a=min(a,b);
            b=max(t,b);
            t=2*a+b;
            pq.push(t);
        }
        return steps;
    }
};
