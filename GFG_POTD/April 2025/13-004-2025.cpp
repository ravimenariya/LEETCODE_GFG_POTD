class Solution {
  public:
    Node* cloneGraph(Node* node) {
        // code here
        unordered_map<int,Node*>ump;
        queue<Node*>q;
        q.push(node);
        ump[node->val]=new Node(node->val);
        
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            for(int i=0;i<curr->neighbors.size();i++)
            {
                if(!ump[curr->neighbors[i]->val])    
                {
                    ump[curr->neighbors[i]->val]=new Node(curr->neighbors[i]->val);
                    q.push(curr->neighbors[i]);
                }
                ump[curr->val]->neighbors.push_back(ump[curr->neighbors[i]->val]);
                
            }
        }
        return ump[node->val];
    }
};
