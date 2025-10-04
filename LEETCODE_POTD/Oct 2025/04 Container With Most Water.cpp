class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),l=0,r=n-1,ans=0;
        while(l<r)
        {
            int h=min(height[l],height[r]),diff=r-l,cap=h*diff;
            if(cap>ans) ans=cap;
            if(height[l]<=height[r])    l++;
            else    r--;
        }
        return ans;
    }
};
