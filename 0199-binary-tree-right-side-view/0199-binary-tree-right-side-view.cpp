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
    vector<vector<int>> levelOrderTraversal( TreeNode* root, vector<vector<int>>&ans ){
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while( !q1.empty() ){
            vector<int> tempArr;
            while( !q1.empty() ){
                TreeNode* tempNode = q1.front();
                if( tempNode->left )    q2.emplace(tempNode->left);
                if( tempNode->right )   q2.emplace(tempNode->right);
                tempArr.emplace_back(tempNode->val);
                q1.pop();
            }
            ans.emplace_back(tempArr);
            q1.swap(q2);
        }
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if( root == nullptr )   return ans;
        vector<vector<int>> levelOrder;
        levelOrder = levelOrderTraversal(root, levelOrder );
        for( int i = 0; i < levelOrder.size(); i++ ){
            int n = levelOrder[i].size();
            ans.emplace_back( levelOrder[i][n-1] );
        }
        return ans;
    }
};