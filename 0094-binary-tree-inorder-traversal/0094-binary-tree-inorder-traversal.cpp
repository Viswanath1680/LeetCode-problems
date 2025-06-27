// Morris traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        auto curr = root;
        while( curr ){
            if( curr->left == nullptr ){
                ans.emplace_back(curr->val);
                curr = curr->right;
            }
            else{
            // form temporary connection between rightmost node and curr
            // If the connection already exists, remove it and 
                auto node = curr->left;
                while( node->right && node->right != curr )    node = node->right;
                if( node->right == curr ){
                    ans.emplace_back(curr->val);
                    node->right = nullptr;
                    curr = curr->right;
                }
                else if( node->right == nullptr ){
                    node->right = curr;
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};