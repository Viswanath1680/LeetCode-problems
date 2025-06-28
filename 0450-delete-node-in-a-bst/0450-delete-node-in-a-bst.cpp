class Solution {
public:
    // replace target node with the predecessor in morris traversal?
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( !root ) return root;
        auto curr = root;
        TreeNode* parent = nullptr;
        bool isfound = false;
        while( curr && !isfound ){
            if( curr->val == key ){
                isfound = true;
                if( !curr->left && !curr->right ){  // laef node
                    if( !parent ) return nullptr;
                    if( parent->left == curr ) parent->left = nullptr;
                    else parent->right = nullptr;
                }
                else if( curr->left ){
                    auto pred_parent = curr, predecessor = curr->left;
                    while( predecessor->right ){
                        pred_parent = predecessor;
                        predecessor = predecessor->right;
                    }
                    curr->val = predecessor->val;
                    // removing predecessor node
                    if( pred_parent == curr )    pred_parent->left = predecessor->left; // no right child for predecessor
                    else    pred_parent->right = predecessor->left; // predecessor->left will atmost have one child and pred_parent != curr. So, pred_parent->right should be predecessor->left;
                }
                else{
                    auto succ_parent = curr;
                    auto successor = curr->right;
                    while( successor->left ){
                        succ_parent = successor;
                        successor = successor->left;
                    }
                    curr->val = successor->val;
                    // remove successor node
                    if( succ_parent == curr )    succ_parent->right = successor->right;
                    else    succ_parent->left = successor->right;
                }
            }
            parent = curr;
            if( curr->val < key )  curr = curr->right;
            else    curr = curr->left;
        }
        return root;
    }
};
