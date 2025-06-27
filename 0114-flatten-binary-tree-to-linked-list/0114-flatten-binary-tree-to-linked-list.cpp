class Solution {
public:
    // Morris traversal idea
    // the "predecessor's" next should be curr->right
    void flatten(TreeNode* root) {
        if( !root ) return;
        auto curr = root;
        while( curr ){
            if( curr->left != nullptr ){
                auto node = curr->left;
                while( node->right )    node = node->right;
                node->right = curr->right;  // predecessor's right is curr_right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};