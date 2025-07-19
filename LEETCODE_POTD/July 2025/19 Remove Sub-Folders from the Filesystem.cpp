class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),[](const string& a,const string& b){
            if(a.size()!=b.size())  return a.size()<b.size();
            return a<b;
        });

        unordered_set<string> st;

        for(string s:folder)
        {
            int i=1;
            int n=s.size();
            while(i<n && s[i]!='/') i++;
            while(i<n && st.find(s.substr(0,i))==st.end())
            {
                i++;
                while(i<n && s[i]!='/') i++;
            }
            if(i>=n)    st.insert(s);
        }

        vector<string> ans(st.begin(),st.end());

        return ans;
    }
};
