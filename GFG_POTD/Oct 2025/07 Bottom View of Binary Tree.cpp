class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            Node* node = curr.first;
            int hd = curr.second;
            
            m[hd] = node->data;
            
            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }
        
        for (const auto& it : m) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
