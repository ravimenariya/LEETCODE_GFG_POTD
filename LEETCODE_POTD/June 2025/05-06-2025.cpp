class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<int,set<char> > ump;
        vector<int> gp(26,0);
        int group=1,n = s1.size(),p1,p2;

        for(int i=0;i<n;i++){
            p1=s1[i]-'a';
            p2=s2[i]-'a';
            if( gp[p1]==0 && gp[p2]==0 ){
                gp[p1]=group;
                gp[p2]=group;
                group++;
            }
            else if(gp[p1]==0)        gp[p1] = gp[p2];
            else if(gp[p2]==0)        gp[p2]=gp[p1];
            else if(gp[p1]!=gp[p2])
            {
                int t=gp[p2];
                for(int&k:gp)
                    if(k==t)    k=gp[p1];
            }
        }

        for(int i=0;i<26;i++)
            ump[gp[i]].insert(i+'a');

        for(int i=0;i<gp.size();i++)
            if(!gp[i])
            {
                gp[i]=group;
                ump[group].insert(i+'a');
                group++;
            }       

        for(int j=0;j<baseStr.size();j++)
            baseStr[j] = *ump[gp[baseStr[j]-'a']].begin();

        return baseStr;

    }
};
