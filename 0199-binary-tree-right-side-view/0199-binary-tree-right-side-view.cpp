class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if( !root ) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while( q.size() ){
            int n = q.size();
            TreeNode* lastnode;
            while( n-- ){
                auto node = q.front();
                q.pop();
                lastnode = node;
                if( node->left )    q.push(node->left);
                if( node->right )   q.push(node->right);
            }
            ans.emplace_back(lastnode->val);
        }
        return ans;
    }
};