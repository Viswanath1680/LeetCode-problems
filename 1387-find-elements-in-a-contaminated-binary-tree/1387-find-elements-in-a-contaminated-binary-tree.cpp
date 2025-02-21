/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    unordered_map<int, bool> ump;
    FindElements(TreeNode* root) {
        if( root )  root->val = 0;
        ump[0] = true;
        if( root->left )    recursive(root, root->left, false);
        if( root->right )   recursive(root, root->right, true);
    }
    
    void recursive(TreeNode* parent, TreeNode* child, bool isRight){
        child->val = 2*(parent->val) + 1;
        if( isRight )   child->val++;
        ump[child->val] = true;
        if( child->left ) recursive(child, child->left, false);
        if( child->right )  recursive(child, child->right, true);
    }

    bool find(int target) {
        return ( ump[target] );
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */