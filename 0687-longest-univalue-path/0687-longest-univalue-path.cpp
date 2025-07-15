// Refer Diameter question
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;

        auto dfs = [&](auto& self, TreeNode* root) -> int{
            if( !root ) return 0;
            int left = self(self, root->left);
            int right = self(self, root->right);
            int dirLeft = 0, dirRight = 0;
            if( root->left ){
                if( root->left->val == root->val )  dirLeft = left + 1;
            }
            if( root->right ){
                if( root->right->val == root->val ) dirRight = right + 1;
            }
            ans = max(ans, dirLeft + dirRight);
            return max(dirLeft, dirRight);
        };

        dfs(dfs, root);
        return ans;
    }
};