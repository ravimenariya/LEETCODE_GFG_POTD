//  3264. Final Array State After K Multiplication Operations I

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        while(k--)
        {
            auto [val,idx]=pq.top();
            pq.pop();
            val*=multiplier;
            nums[idx]=val;
            pq.push({val,idx});
        }
        return nums;
    }
};
