class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();

        // Step 1: find pivot (index of smallest element)
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;

        int count = 0;

        // Step 2: count in right sorted part [pivot .. n-1]
        count += upper_bound(arr.begin() + pivot,
                             arr.end(),
                             x)
                 - (arr.begin() + pivot);

        // Step 3: count in left sorted part [0 .. pivot-1]
        if (pivot > 0) {
            count += upper_bound(arr.begin(),
                                 arr.begin() + pivot,
                                 x)
                     - arr.begin();
        }

        return count;
    }
};
