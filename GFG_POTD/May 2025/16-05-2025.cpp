class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int k = arr.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> range = {-1000000, 1000000}; 
        int maxEle = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({arr[i][0], i, 0});
            maxEle = max(maxEle, arr[i][0]);
        }

        while (!pq.empty()) {
            int minEle = pq.top()[0];         
            int minListIdx = pq.top()[1];     
            int minEleIdx = pq.top()[2];      
            pq.pop();

            if (maxEle - minEle < range[1] - range[0]) {
                range[0] = minEle;
                range[1] = maxEle;
            }

            if (minEleIdx + 1 < arr[minListIdx].size()) {
                int nextEle = arr[minListIdx][minEleIdx + 1];
                pq.push({nextEle, minListIdx, minEleIdx + 1});
                maxEle = max(maxEle, nextEle); 
            } else {
                break;
            }
        }

        return range;
    }
};
