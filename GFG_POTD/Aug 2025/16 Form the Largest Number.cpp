class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string>v;
        for(int i:arr)  v.push_back(to_string(i));
        sort(v.begin(),v.end(),[](string&a,string&b){
            return a+b > b+a;
        });
        string ans="";
        int i=0,n=v.size();
        while(i<n && v[i]=="0")
        {
            ans="0";
            i++;
        }
        while(i<n)   ans+=v[i++];
        return ans;
    }
};
