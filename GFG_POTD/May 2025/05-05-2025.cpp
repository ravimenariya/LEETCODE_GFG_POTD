class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int l = 0, r = arr.size() - 1;
    
        while (r >= l) {
            int mid = l + (r - l) / 2;
    
            // Check the middle 3 positions
            if (arr[mid] == target) 
                return mid;
            if (mid > l && arr[mid - 1] == target) 
                return mid - 1;
            if (mid < r && arr[mid + 1] == target) 
                return mid + 1;
    
            // Search in left subarray
            if (arr[mid] > target) 
                r = mid - 2;
    
            // Search in right subarray
            else 
                l = mid + 2;
        }
    
        // Element not found
        return -1; 
    }
};
