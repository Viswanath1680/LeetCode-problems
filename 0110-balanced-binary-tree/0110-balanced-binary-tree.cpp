class Solution {
public:
    // Linear solution
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        auto recursive = [&](auto& self, TreeNode* root) -> int{
            if( !root ) return 0;
            auto left = self(self, root->left);
            auto right = self(self, root->right);
            if( abs(left - right) > 1 ) ans = false;
            return max(left, right) + 1;
        };

        recursive(recursive, root);
        return ans;
    }
};