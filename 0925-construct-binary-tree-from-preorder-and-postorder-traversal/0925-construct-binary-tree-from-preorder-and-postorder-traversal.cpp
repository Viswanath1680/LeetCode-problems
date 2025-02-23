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
class Solution {
public:
    TreeNode* recursive(vector<int>& preorder, unordered_map<int,int>& ump, int i1, int i2, int j1, int j2){
        if( i1 > i2 || j1 > j2 )    return nullptr;
        TreeNode* root = new TreeNode(preorder[i1]);

        if( i1 != i2 ){
            int left_val = preorder[i1+1];
            int indx = ump[ left_val ];
            int left_size = indx - j1 + 1;

            root->left = recursive(preorder, ump, i1+1, i1 + left_size, j1, indx);
            root->right = recursive(preorder, ump, i1+left_size+1, i2, indx+1, j2-1);
        }
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> ump;
        int n = postorder.size();
        for(int i = 0; i < n; i++)  ump[ postorder[i] ] = i;
        return recursive(preorder, ump, 0, n-1, 0, n-1);
    }
};