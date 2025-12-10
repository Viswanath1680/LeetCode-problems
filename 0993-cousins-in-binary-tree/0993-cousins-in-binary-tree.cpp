using vi = vector<int>;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if( !root ) return false;
        
        auto rootToNode = [&](auto& self, TreeNode* root, vi& path, int n ) -> bool{
            if( !root ) return false;

            path.emplace_back(root->val);
            if( root->val == n )    return true;
            if( self(self, root->left, path, n) || self(self, root->right, path, n) ) return true;
            path.pop_back();
            return false;
        };

        vi path_x, path_y;
        rootToNode(rootToNode, root, path_x, x);
        rootToNode(rootToNode, root, path_y, y);
        if( path_x.back() != x || path_y.back() != y )  return false;
        if( path_x.size() != path_y.size() )    return false;
        int n = path_x.size();
        return ( path_x[n-2] != path_y[n-2] );

    }
};