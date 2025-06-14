class Solution {
public:
    bool checkSymmetric(Node* first, Node* second) {
        if (!first && !second)
            return true;

        if (first && second && first->data == second->data)
            return checkSymmetric(first->left, second->right) && checkSymmetric(first->right, second->left);

        return false;
    }

    bool isSymmetric(struct Node* root) {
        if (!root)
            return true;
        return checkSymmetric(root->left, root->right);
    }
};
