class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        auto dfs = [&](auto& self, TreeNode* root, int sum) -> bool{
            if( !root ) return false;
            if( !root->left && !root->right ){
                if( sum + root->val == targetSum )  return true;
            }
            if( self(self, root->left, sum + root->val) ) return true;
            if( self(self, root->right, sum + root->val ) ) return true;
            return false;
        };

        if( dfs(dfs, root, 0) ) return true;
        return false;
    }
};