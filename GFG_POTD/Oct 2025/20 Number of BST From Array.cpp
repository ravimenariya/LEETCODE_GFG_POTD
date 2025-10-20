class Solution {
    int fact(int n){
        if(!n)  return 1;
        return n*fact(n-1);
    }
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        unordered_map<int,int>index;
        int n=arr.size();
        for(int i=0;i<n;i++)    index[arr[i]]=i;
        sort(arr.begin(),arr.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int left=i;
            int catL=fact(2*left)/(fact(left+1)*fact(left));
            int right=n-i-1;
            int catR=fact(2*right)/(fact(right+1)*fact(right));
            ans[index[arr[i]]]=catL*catR;
        }
        return ans;
    }
};
