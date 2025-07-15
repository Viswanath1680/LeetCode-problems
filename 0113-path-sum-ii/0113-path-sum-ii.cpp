class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;

        auto dfs = [&](auto& self, TreeNode* root, vector<int>& path, int sum){
            if( !root ) return;
            if( !root->left && !root->right ){
                if( sum + root->val == targetSum )  {
                    path.emplace_back(root->val);
                    paths.emplace_back(path);
                    path.pop_back();
                }
                return;
            }
            path.emplace_back( root->val );
            self(self, root->left, path, sum + root->val);
            self(self, root->right, path, sum + root->val);
            path.pop_back();
        };

        vector<int> path;
        dfs(dfs, root, path, 0);
        return paths;
    }
};