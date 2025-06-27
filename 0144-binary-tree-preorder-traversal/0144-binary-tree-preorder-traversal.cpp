class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        auto curr = root;
        while( curr ){
            if( curr->left == nullptr ){
                ans.emplace_back(curr->val);
                // ans.emplace_back(curr->val);
                curr = curr->right;
            }
            else{
            // form temporary connection between rightmost node and curr
            // If the connection already exists, remove it and 
                auto node = curr->left;
                while( node->right && node->right != curr )    node = node->right;
                if( node->right == curr ){
                    node->right = nullptr;
                    curr = curr->right;
                }
                else if( node->right == nullptr ){
                    ans.emplace_back(curr->val);    // First time visiting
                    node->right = curr;
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};