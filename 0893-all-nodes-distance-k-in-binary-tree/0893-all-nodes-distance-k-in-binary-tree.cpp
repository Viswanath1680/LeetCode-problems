//  https://www.youtube.com/watch?v=i9ORlEy6EsI
class Solution {
public:
    void parentMapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& ump){
        queue<TreeNode*> q;
        q.push(root);
        while( q.size() ){
            int n = q.size();
            while( n-- ){
                auto node = q.front();
                q.pop();
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
        // for( auto it : ump ){
        //     cout << it.first->val << " " << it.second->val << endl;
        // }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if( !root ) return ans;
        unordered_map<TreeNode*, TreeNode*> ump;
        parentMapping(root, ump);

        queue<TreeNode*> q;
        q.push( target );
        unordered_set<TreeNode*> s;
        s.insert(target);
        int distance = 0;
        while( distance < k && q.size() ){
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
        if( distance == k ){
            while( q.size() ){
                auto node = q.front();
                ans.emplace_back(node->val);
                q.pop();
            }
        }
        return ans;
    }
};