class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int target) {
        if( !root ) return root;
        auto curr = root;
        while( curr ){
            if( curr->val == target )   return curr;
            if( curr->val < target )    curr = curr->right;
            else    curr = curr->left;
        }
        return nullptr;
    }
};