class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size(),i=(n-1)/2,j=i+1;
        while(k && j<n)
        {
            int diff=arr[j]-arr[i];
            int dist=j-i;
            int avail=min(k/dist,diff);
            arr[i]+=avail;
            k-=(avail*dist);
            if(k) j++;
        }
        arr[i]+=(k/(n-i));
        k=k%(n-i);
        if (n % 2 ) return arr[i];
        if (k == 0 && j - i == 1) return (arr[i] + arr[j]) / 2;
        if ((n - i - 1) >= k) return (arr[i] * 2 + 1) / 2;
        return arr[i];
    }
};
