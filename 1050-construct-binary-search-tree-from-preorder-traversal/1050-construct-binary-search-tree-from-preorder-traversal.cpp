class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        auto recursive = [&](auto& self, int l, int r) -> TreeNode*{
            if( l > r ) return nullptr;
            auto root = new TreeNode(preorder[l]);
            int ind = l;
            while( ind <= r && preorder[ind] <= preorder[l]  )   ind++;
            ind--;
            root->left = self(self, l+1, ind);
            root->right = self(self, ind+1, r);
            return root;
        };

        auto root = recursive(recursive, 0, n-1);
        return root;
    }
};