class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        if( !root ) return ans;

        auto dfs = [&](auto& self, TreeNode* root) -> void{
            if( !root ) return;
            ans += to_string( root->val );
            if( !root->left && root->right ){
                ans += "()";
                ans += '(';
                self(self, root->right);
                ans += ')';
            }
            else{
                if( root->left ){
                    ans += '(';
                    self(self, root->left);
                    ans += ')';
                }
                if( root->right){
                    ans += '(';
                    self(self, root->right);
                    ans += ')';
                }
            }
        };

        dfs(dfs, root);
        return ans;
    }
};