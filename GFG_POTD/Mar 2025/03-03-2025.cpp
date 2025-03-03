
// problem -> https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int k) {
        deque<pair<int, int>> maxq; 
        deque<pair<int, int>> minq;
        int l = 0, ans = 0, ansl = 0;

        for (int i = 0; i < arr.size(); i++) {
            while (!maxq.empty() && maxq.back().first < arr[i])
                maxq.pop_back();
            maxq.push_back({arr[i], i});

            while (!minq.empty() && minq.back().first > arr[i])
                minq.pop_back();
            minq.push_back({arr[i], i});

            while (!maxq.empty() && !minq.empty() && (maxq.front().first - minq.front().first) > k) {
                l++;
                if (maxq.front().second < l)
                    maxq.pop_front();
                if (minq.front().second < l)
                    minq.pop_front();
            }

            if ((i - l + 1) > ans) {
                ans = i - l + 1;
                ansl = l;
            }
        }

        return vector<int>(arr.begin() + ansl, arr.begin() + ansl + ans);
    }
};
