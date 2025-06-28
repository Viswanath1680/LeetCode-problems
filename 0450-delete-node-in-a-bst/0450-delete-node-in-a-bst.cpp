class Solution {
public:
    // replace target node with the predecessor in morris traversal?
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->val)    root->left = deleteNode(root->left, key);
        else if (key > root->val)    root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            auto parent = root, pred = root->left;
            while ( pred->right ) {
                parent = pred;
                pred = pred->right;
            }
            root->val = pred->val;
            if ( parent == root )    parent->left = pred->left;
            else    parent->right = pred->left;
        }
        return root;
    }
};