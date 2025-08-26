class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float max_diag=0;
        int ans=0;
        for(auto v:dimensions)
        {
            float diag=sqrt(v[0]*v[0]+v[1]*v[1]);
            if(diag>max_diag)   {
                max_diag=diag;
                ans=v[0]*v[1];
            }
            else if(diag==max_diag) 
                ans=max(ans,v[0]*v[1]);
        }
        return ans;
    }
};
