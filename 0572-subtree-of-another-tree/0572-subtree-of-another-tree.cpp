class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( !p && !q )  return true;
        if( !p || !q )  return false;
        if( p->val != q->val )  return false;
        return ( isSameTree(p->left, q->left) && isSameTree(p->right, q->right) );
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if( !root && !subRoot ) return true;
        if( !root || !subRoot ) return false;
        queue<TreeNode*> q;
        q.push(root);
        while( q.size() ){
            int n = q.size();
            while( n-- ){
                auto node = q.front();
                q.pop();
                if( isSameTree(subRoot, node) ) return true;
                if( node->left )    q.push( node->left );
                if( node->right )   q.push( node->right );
            }
        }
        return false;
    }
};