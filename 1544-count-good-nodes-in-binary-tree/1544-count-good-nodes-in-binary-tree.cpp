class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        auto recursive = [&](auto& self, TreeNode* root, int maxtillnow) -> void{
            if( !root ) return;
            if( root->val >= maxtillnow ){
                maxtillnow = root->val;
                ans++;
            }
            self(self, root->left, maxtillnow);
            self(self, root->right, maxtillnow);
        };

        recursive(recursive, root, INT_MIN);
        return ans;
    }
};