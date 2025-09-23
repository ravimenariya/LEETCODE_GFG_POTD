class Solution {
public:
    int compareVersion(string version1, string version2) {

        auto get=[](string version){
            vector<int>v;
            int i=0,n=version.size();
            while(i<n)
            {
                string str="";
                while(i<n && version[i]=='0')  i++;
                if(i==n || version[i]=='.')    str="0";
                while(i<n && version[i]!='.')
                {
                    str+=version[i];
                    i++;
                }
                v.push_back(stoi(str));
                i++;
            }
            return v;
        };

        vector<int>v1=get(version1);
        vector<int>v2=get(version2);

        while(v1.size()<v2.size())  v1.push_back(0);
        while(v2.size()<v1.size())  v2.push_back(0);

        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]>v2[i]) return 1;
            else if(v1[i]<v2[i])    return -1;
        }
        return 0;        
    }
};
