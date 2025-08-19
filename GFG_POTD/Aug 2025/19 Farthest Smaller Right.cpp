// APPROACH 1 - BINARY SEARCH

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>v(n);
        v[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) v[i]=min(v[i+1],arr[i]);
        
        for(int i=0;i<n;i++)
        {
            int low=i+1,high=n-1,mid=-1;
            while(low<=high)
            {
                if(v[low]>=arr[i])  break;
                mid=low+(high-low)/2;
                if(v[mid]>=arr[i])   high=mid-1;
                else                 low=mid+1;
            }
            if(mid==-1) v[i]=-1;
            else        v[i]=mid;
        }
        return v;
    }
};



// APPROACH 2 - SORTING  

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        vector<pair<int,int>>v;
        int n=arr.size();
        for(int i=0;i<n;i++)   v.push_back({arr[i],i});
        sort(v.begin(),v.end());
        
        vector<int>idx;
        int maxi=-1;
        for(auto i:v){
            idx.push_back(maxi);
            maxi=max(maxi,i.second);
        }
        
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(idx[i]>v[i].second) ans[v[i].second]=idx[i];    
        }
        return ans;
    }
};
