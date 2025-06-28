class Solution {
public:
    // Just search for an empty space
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto node = new TreeNode(val);
        if( !root ) return node;
        auto curr = root;
        while( 1 ){
            if( curr->val < val ){
                if( curr->right )   curr = curr->right;
                else{
                    curr->right = node;
                    break;
                }
            }
            else{
                if( curr->left )    curr = curr->left;
                else{
                    curr->left = node;
                    break;
                }
            }
        }
        return root;
    }
};