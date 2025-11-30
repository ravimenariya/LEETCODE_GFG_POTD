int speedup = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int i : nums) {
            totalSum += i;
        }
        
        int req = totalSum % p;
        if (req == 0) return 0;

        unordered_map<int, int> prefixMap;  // Map to store prefix sums mod p
        prefixMap[0] = -1;  // To handle cases where we can remove from the start
        long long prefixSum = 0;
        int minSize = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - req + p) % p;
            
            if (prefixMap.find(target) != prefixMap.end()) {
                minSize = min(minSize, i - prefixMap[target]);
            }
            
            prefixMap[prefixSum] = i;  // Store the current prefix sum mod p with its index
        }
        
        // If no valid subarray is found, return -1
        return minSize == nums.size() ? -1 : minSize;
    }
};
