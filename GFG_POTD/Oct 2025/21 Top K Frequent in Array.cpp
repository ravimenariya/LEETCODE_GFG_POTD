class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>freq;
        for(int i:arr)  freq[i]++;
        priority_queue<pair<int,int>>pq;
        for(auto i:freq)    pq.push({i.second,i.first});
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
