class Solution {
public:
//  diameter = height of left tree + height of right tree
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if( !root ) return ans;
        auto height = [&](auto& self, TreeNode* root) -> int{
            if( !root ) return 0;
            auto left = self(self, root->left);
            auto right = self(self, root->right);
            ans = max(ans, left+right);
            return max(left, right) + 1;    // returns height of root
        };
        height(height, root);
        return ans;
    }
};