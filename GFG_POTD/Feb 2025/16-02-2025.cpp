
// problem -> https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int>v;
        queue<Node*>q;
        q.push(root);
        v.push_back(root->data);
        
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(root->left)  
            {
                q.push(root->left);
                v.push_back(root->left->data);
            }
            else            v.push_back(0);
            if(root->right)  
            {
                q.push(root->right);
                v.push_back(root->right->data);
            }
            else            v.push_back(0);
        }
        
        // for(int&i:v)    cout<<i<<" ";
        // cout<<endl;
        return v;
        
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        
        Node* root=new Node(arr[0]);
        queue<Node*>q;
        q.push(root);
        int n=arr.size(),i=1;

        
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            
            if(i<n && arr[i])
            {
                Node * temp=new Node(arr[i]);
                curr->left=temp;
                q.push(temp);
            }
            i++;
            if(i<n && arr[i])
            {
                Node * temp=new Node(arr[i]);
                curr->right=temp;
                q.push(temp);
            }
            i++;
            
        }
        
        return root;
    }
};
