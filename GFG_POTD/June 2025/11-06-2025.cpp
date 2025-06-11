class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int,int>>stk;
        int c=0;
        for(int i=0;i<color.size();i++)
            if(!stk.empty() && stk.top()==make_pair(color[i],radius[i])){   
                stk.pop();   
                c+=2;  
            }
            else    stk.push({color[i],radius[i]});
        return color.size()-c;
    }
};
