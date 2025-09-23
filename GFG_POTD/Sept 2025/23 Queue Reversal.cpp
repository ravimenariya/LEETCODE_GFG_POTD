class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int>stk;
        while(!q.empty())
        {
           stk.push(q.front());
           q.pop();
        }
        while(!stk.empty())
        {
            q.push(stk.top());
            stk.pop();
        }
    }
};
