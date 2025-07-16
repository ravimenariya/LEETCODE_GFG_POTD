class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int r=2,even=0,odd=0,altr=0;
        for(int i:nums){
            if(i%2!=r){
                altr++;
                r=i%2;
            }
            if(i%2==0)  even++;
            else        odd++;
        }
        return max({odd,even,altr});
    }
};
