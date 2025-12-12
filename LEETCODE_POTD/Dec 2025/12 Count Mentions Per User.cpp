class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            int k = stoi(a[1]), l = stoi(b[1]);
            if (k == l) {
                if (a[0] == "OFFLINE")
                    return true;
                return false;
            }
            return k < l;
        });

        int currTime = 0, globalAdd = 0;
        vector<int> mentions(n, 0), online_time(n, 0);

        for (auto e : events) {
            currTime = stoi(e[1]);

            if (e[0] == "MESSAGE") {
                if (e[2] == "ALL")
                    globalAdd++;
                else if (e[2] == "HERE") {
                    for (int i = 0; i < n; i++)
                        if (online_time[i] <= currTime)
                            mentions[i]++;
                } else {
                    std::stringstream ss(e[2]);
                    string id;
                    while (ss >> id) {
                        int ID = stoi(id.substr(2));
                        mentions[ID]++;
                    }
                }
            } else {
                int id = stoi(e[2]);
                online_time[id] = currTime + 60;
            }
        }

        for (int& i : mentions)
            i += globalAdd;

        return mentions;
    }
};
