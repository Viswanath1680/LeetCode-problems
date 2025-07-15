class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int leftMost;
        queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() ){
            int n = q.size();
            for( int i = 0; i < n; i++ ){
                auto node = q.front(); q.pop();
                if( i == 0 )    leftMost = node->val;
                if( node->left )    q.push( node->left );
                if( node->right )   q.push( node->right );
            }
        }
        return leftMost;
    }
};