class Solution {
public:
    // recursive using lambda function
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if( !root ) return ans;
        auto recursive = [&](auto& self, TreeNode* root) -> void{
            if( !root ) return;
            self(self, root->left);
            self(self, root->right);
            ans.emplace_back(root->val);
        };
        recursive(recursive, root);
        return ans;
    }
};