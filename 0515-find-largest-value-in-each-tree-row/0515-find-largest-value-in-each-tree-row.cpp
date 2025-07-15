class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> largest;
        if( !root ) return largest;
        queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() ){
            int n = q.size(), maxi = INT_MIN;
            for( int i = 0; i < n; i++ ){
                auto node = q.front(); q.pop();
                maxi = max(maxi, node->val);
                if( node->left )    q.push( node->left );
                if( node->right )   q.push( node->right );
            }
            largest.emplace_back(maxi);
        }
        return largest;
    }
};