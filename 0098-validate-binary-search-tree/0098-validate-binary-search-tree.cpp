class Solution {
public:
    vector<int> morrisInorder(TreeNode* root){
        vector<int> ans;
        auto curr = root;
        while( curr ){
            if( curr->left == nullptr ){
                ans.emplace_back(curr->val);
                curr = curr->right;
            }
            else{
                auto predecessor = curr->left;
                while( predecessor->right && predecessor->right != curr  )    predecessor = predecessor->right;
                if( predecessor->right == curr ){
                    predecessor->right = nullptr;
                    ans.emplace_back(curr->val);
                    curr = curr->right;
                }
                else{
                    predecessor->right = curr;
                    curr = curr->left;
                }
            }
        }
        return ans;
    }

    bool isValidBST(TreeNode* root) {
        if( !root ) return true;
        vector<int> inorder = morrisInorder(root);
        int n = inorder.size();
        for( int i = 0; i < n-1; i++ )  if( inorder[i] >= inorder[i+1] )    return false;
        return true;
    }
};