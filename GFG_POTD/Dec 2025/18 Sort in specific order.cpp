class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(),[](int&a,int&b){
            if(a%2){
                if(b%2) return a>b;
                else    return true;
            }
            else {
                if(b%2) return false;
                else    return a<b;
            }
        });
    }
};
