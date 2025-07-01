class Solution {
public:

    bool findTarget(TreeNode* root, int target) {
        vector<int> inorder;
        auto recursive = [&](auto& self, TreeNode* root) -> void{
            if( !root ) return;
            self(self, root->left);
            inorder.emplace_back(root->val);
            self(self, root->right);
        };
        recursive(recursive, root);
        int l = 0, r = inorder.size() -1;
        while( l < r ){
            if( inorder[l] + inorder[r] == target ) return true;
            if( inorder[l] + inorder[r] > target )  r--;
            else    l++;
        }
        return false;
    }
};