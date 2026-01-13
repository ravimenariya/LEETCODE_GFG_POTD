class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==5){
                m[arr[i]]++;
            } else if(arr[i]==10 && m[5]>0){
                m[5]-=1;
                m[arr[i]]++;
            } else if(arr[i]==20 && m[10]>0 && m[5]>0){
                m[arr[i]]++;
                m[5]-=1;
                m[10]-=1;
            } else if(arr[i]==20 && m[5]>=3){
                m[arr[i]]++;
                m[5]-=3;
            } else return false;
        }
        return true;
    }
};
