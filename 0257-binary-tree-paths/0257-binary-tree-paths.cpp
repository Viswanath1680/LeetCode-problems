class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        auto recursive = [&](auto& self, TreeNode* root, string temp) -> void{
            if( !root ) return ;
            temp += to_string(root->val);
            if( !root->left && !root->right ){
                ans.emplace_back(temp);
                return;
            }
            temp += "->";
            self(self, root->left, temp);
            self(self, root->right, temp);
        };
        recursive(recursive, root, "");
        return ans;
    }
};