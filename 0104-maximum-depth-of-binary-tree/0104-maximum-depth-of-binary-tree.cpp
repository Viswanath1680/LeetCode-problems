class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        if( !root ) return ans;
        auto recursive = [&](auto& self, TreeNode* root, int height) -> int{
            if( !root ) return height;
            height++;
            int left = self(self, root->left, height);
            int right = self(self, root->right, height);
            ans = max(ans, max(left, right));
            return max(left, right);
        };
        recursive(recursive, root, 0);
        return ans;
    }
};