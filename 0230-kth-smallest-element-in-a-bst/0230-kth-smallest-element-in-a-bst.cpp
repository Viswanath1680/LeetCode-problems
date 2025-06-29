class Solution {
public:
    int inorderTraversal(TreeNode* root, int k) {
        auto curr = root;
        int ans, counter = 0;
        while( curr ){
            if( curr->left == nullptr ){
                // ans.emplace_back(curr->val);
                counter++;
                if( counter == k )  ans = curr->val;
                curr = curr->right;
            }
            else{
            // form temporary connection between rightmost node and curr
            // If the connection already exists, remove it and 
                auto node = curr->left;
                while( node->right && node->right != curr )    node = node->right;
                if( node->right == curr ){
                    // ans.emplace_back(curr->val);
                    counter++;
                    if( counter == k )  ans = curr->val;
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


    int kthSmallest(TreeNode* root, int k) {
        int ans = inorderTraversal(root, k);
        return ans;
    }
};
