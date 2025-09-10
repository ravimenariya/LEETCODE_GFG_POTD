class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {

        unordered_map<int,vector<int>>friends;
        for(auto v:friendships){
            friends[v[0]].push_back(v[1]);
            friends[v[1]].push_back(v[0]);
        }

        set<int>ump; // this will keep track of all the users who have problem in communicating with any of their friends
        for(auto [user,frds]:friends)
        {
            set<int>avail_lgs;
            for(int l:languages[user-1])    avail_lgs.insert(l);

            for(int frd:frds)
            {
                int f=0;
                for(int l:languages[frd-1])
                {
                    if(avail_lgs.find(l)!=avail_lgs.end())
                    {
                        f=1;
                        break;
                    }
                }
                if(!f){
                    ump.insert(user);
                    ump.insert(frd);
                }
            }
        }

        // find the number of users need to learn new language to resolve communication problem
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int count=0;
            for(int user:ump)
            {
                int f=0;
                for(int l:languages[user-1])
                {
                    if(l==i){
                        f=1;
                        break;
                    }
                }
                if(!f)  count++;
            }
            ans=min(ans,count);
        }

        return ans;
    }
};
