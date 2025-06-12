class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        int n=arr.size(),l=0,r=n-1,mid,i,j=-1;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(arr[mid]==x)             break;
            else if(arr[mid]>x) r=mid-1;
            else                l=mid+1;
        }
        if(arr[mid]==x)
        {
            i=mid-1;
            j=mid+1;
        }
        else if(arr[mid]>x)
        {
            i=mid-1;
            j=mid;
        }
        else {
            i=mid;
            j=mid+1;
        }

        vector<int>ans;
        while(k--)
        {
            int m1=INT_MAX,m2=INT_MAX;
            if(i>=0)    m1=x-arr[i];
            if(j<n)     m2=arr[j]-x;
            if(m1<m2)   ans.push_back(arr[i--]);
            else        ans.push_back(arr[j++]);
        }
        return ans;
    }
};
