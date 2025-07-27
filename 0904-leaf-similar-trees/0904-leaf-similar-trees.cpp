class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if( !root1 && !root2 )  return true;
        if( !root1 || !root2 )    return false;

        auto dfs = [&](auto& self, TreeNode* root, vector<int>& leaf_sequence) -> void{
            if( !root ) return;
            if( !root->left && !root->right ){
                leaf_sequence.emplace_back(root->val);
                return;
            }
            self(self, root->left, leaf_sequence);
            self(self, root->right, leaf_sequence);
        };

        vector<int> leaf_sequence1, leaf_sequence2;
        dfs(dfs, root1, leaf_sequence1);
        dfs(dfs, root2, leaf_sequence2);
        return (leaf_sequence1 == leaf_sequence2);
    }
};