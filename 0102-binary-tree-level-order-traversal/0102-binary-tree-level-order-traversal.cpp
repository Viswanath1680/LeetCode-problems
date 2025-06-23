class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;     
        if( !root ) return ans;
        q.push(root);
        while( q.size() ){
            int n = q.size();
            vector<int> temp;
            while( n-- ){
                auto node = q.front();
                q.pop();
                temp.emplace_back(node->val);
                if( node->left )    q.push(node->left);
                if( node->right )   q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};