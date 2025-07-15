class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {

        int sum = 0;
        auto reverseInorder = [&](auto& self, TreeNode* root) -> void{
            if( !root ) return;
            self(self, root->right);
            sum += root->val;
            root->val = sum;
            self(self, root->left);
        };
        reverseInorder(reverseInorder, root);
        return root;
    }
};