class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        auto dfs = [&](auto& self, TreeNode* root, bool isLeft ) -> void{
            if( !root ) return;
            if( !root->left && !root->right ){
                if( isLeft )    sum += root->val;
                return;
            }
            self(self, root->left, true);
            self(self, root->right, false);
        };
        
        dfs(dfs, root, false);
        return sum;
    }
};