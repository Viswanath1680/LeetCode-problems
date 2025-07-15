class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> traversal;

        auto dfs = [&](auto& self, TreeNode* root) -> void{
            if( !root ) return;
            self(self, root->left);
            traversal.emplace_back(root->val);
            self(self, root->right);
        };

        dfs(dfs, root);
        sort(traversal.begin(),traversal.end());
        int ans = INT_MAX;
        for( int i = 1 ; i < traversal.size(); i++ )    ans = min(ans, traversal[i] - traversal[i-1]);
        return ans;
    }
};