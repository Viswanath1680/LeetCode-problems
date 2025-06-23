class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if( !root ) return ans;
        auto recursive = [&](auto& self, TreeNode* root) -> void{
            if( !root ) return;
            self(self, root->left);
            ans.emplace_back(root->val);
            self(self, root->right);
        };
        recursive(recursive, root);
        return ans;
    }
};