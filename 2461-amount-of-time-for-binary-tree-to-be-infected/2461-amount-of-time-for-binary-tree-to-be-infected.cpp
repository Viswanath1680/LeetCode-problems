// https://www.youtube.com/watch?v=i9ORlEy6EsI
class Solution {
public:
    TreeNode* parentMapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& ump, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* start_node;
        while( q.size() ){
            int n = q.size();
            while( n-- ){
                auto node = q.front();
                q.pop();
                if( node->val == start )    start_node = node;
                if( node->left ){
                    ump[node->left] = node;
                    q.push( node->left );
                }
                if( node->right ){
                    ump[ node->right ] = node;
                    q.push( node->right );
                }
            }
        }
        return start_node;
    }

    int amountOfTime(TreeNode* root, int start) {
        if( !root ) return 0;
        unordered_map<TreeNode*, TreeNode*> ump;
        auto start_node = parentMapping(root, ump, start);

        queue<TreeNode*> q;
        q.push( start_node );
        unordered_set<TreeNode*> s;
        s.insert(start_node);
        int distance = 0;
        while( q.size() ){
            int n = q.size();
            while( n-- ){
                auto node = q.front();
                q.pop();
                // now move radially outward
                if( node->left ){
                    if( s.find( node->left ) == s.end() ){
                        s.insert(node->left);
                        q.push(node->left);
                    }
                }
                if( node->right ){
                    if( s.find( node->right ) == s.end() ){
                        s.insert(node->right);
                        q.push(node->right);
                    }
                }
                if( ump[node] ){
                    if( s.find( ump[node] ) == s.end() ){
                        s.insert( ump[node] );
                        q.push( ump[node] );
                    }
                }
            }
            distance++;
        }
        return distance-1;
    }
};