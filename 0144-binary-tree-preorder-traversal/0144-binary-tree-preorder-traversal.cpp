class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if( !root ) return ans;
        // Lambda function
        auto recursive = [&](auto& self, TreeNode* root ) -> void{
            if( !root ) return;
            ans.emplace_back(root->val);
            self(self, root->left);
            self(self, root->right);
        };

        recursive(recursive, root);
        return ans;
    }
};