class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left=0,right=arr.size()-1,ans=0;
        while(left<right)
        {
            int w=min(arr[left],arr[right])*(right-left);
            ans=max(ans,w);
            if(arr[left]<arr[right])    left++;
            else    right--;
        }
        return ans;
    }
};
