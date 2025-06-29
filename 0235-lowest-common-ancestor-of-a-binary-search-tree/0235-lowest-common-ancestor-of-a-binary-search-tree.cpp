class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto curr = root;
        int p_val = p->val, q_val = q->val;
        while( curr ){
            int curr_val = curr->val;
            // cout << curr_val << endl;
            if( curr_val > p_val && curr_val > q_val )  curr = curr->left;
            else if( curr_val < p_val && curr_val < q_val )    curr = curr->right;
            else return curr;
        }
        return p;
    }
};