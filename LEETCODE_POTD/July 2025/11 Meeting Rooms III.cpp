class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>>avail_room;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>free_first;

        for(int i=0;i<n;i++)    avail_room.push(i);
        sort(meetings.begin(),meetings.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])  return a[1]<b[1];
            return a[0]<b[0];
        });

        unordered_map<int,int>freq;
        long long curr=0,max_room,max_freq=0,room_no;

        for(auto v:meetings)
        {
            if(v[0]>curr)   curr=v[0];
            while(!free_first.empty() && free_first.top().first<=curr){
                auto p=free_first.top();
                avail_room.push(p.second);
                free_first.pop();
            }
            if(!avail_room.empty())
            {
                room_no=avail_room.top();
                avail_room.pop();
                free_first.push({curr+(v[1]-v[0]),room_no});
            }
            else {
                auto p=free_first.top();
                free_first.pop();
                curr=p.first;
                free_first.push({curr+(v[1]-v[0]),p.second});
                room_no=p.second;
            }
                // cout<<"r="<<room_no<<", fr="<<curr+(v[1]-v[0])<<endl;
            if(++freq[room_no]>max_freq)
            {
                max_freq=freq[room_no];
                max_room=room_no;
            }
            else if(freq[room_no]==max_freq && room_no<max_room)    max_room=room_no;
        }
        return max_room;
    }
};
