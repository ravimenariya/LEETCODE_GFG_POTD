class Solution {
public:
    string clearStars(string s) {
        int n = s.length();

        priority_queue<pair<char ,int> , vector<pair<char , int>>, greater<>>pq; 

        for(int i = 0 ; i <n; i++){
            if(s[i] == '*'){
                if(!pq.empty()){
                    auto curr = pq.top();
                    char ch = curr.first ; 
                    int idx = curr.second*-1; 
                    pq.pop();

                    s[idx] = '*';
                }
            }
            else pq.push({s[i],i*-1});
        }
           
           string result = "";
        for(int i = 0 ; i <n; i++){
            if(s[i]!='*') result.push_back(s[i]);
        }
        return result; 
    }
};
