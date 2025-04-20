class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int n=arr.size(),i;
        vector<bool>v(n+1,false);
        for(i=0;i<n;i++)    
            if(v[arr[i]])    break;
            else             v[arr[i]]=true;
        return arr[i];
    }
};
