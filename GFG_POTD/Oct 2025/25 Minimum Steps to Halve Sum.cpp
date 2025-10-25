class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        set<pair<double,int>>st;
        double org_sum=0;
        for(int i=0;i<arr.size();i++)
        {
            st.insert({arr[i],i});
            org_sum+=arr[i];
        }
        
        double new_sum=org_sum;
        org_sum/=2;
        int opr=0;
        while(new_sum>org_sum)
        {
            auto p=*(st.rbegin());
            st.erase(p);
            double t=p.first/2.0;
            new_sum-=t;
            opr++;
            st.insert({t,p.second});
        }
        return opr;
    }
};
