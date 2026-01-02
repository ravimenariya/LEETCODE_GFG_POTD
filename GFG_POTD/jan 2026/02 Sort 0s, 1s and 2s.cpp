class Solution {
  public:
    void sort012(vector<int>& arr) {
        vector<int>fr(3,0);
        for(int&i:arr)fr[i]++;
        int i=0;
        while(fr[0]--)   arr[i++]=0;
        while(fr[1]--)   arr[i++]=1;
        while(fr[2]--)   arr[i++]=2;
    }
};
