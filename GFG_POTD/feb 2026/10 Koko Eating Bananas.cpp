class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int l=1,h=*max_element(arr.begin(),arr.end()),ans=k;
        while(l<=h){
            float m=l+(h-l)/2;
            int hours=0;
            for(int i:arr)
                hours+=(ceil(i/m));
            if(hours>k)         l=m+1;
            else {
                ans=m;
                h=m-1;
            }
        }
        return ans;
    }
};
