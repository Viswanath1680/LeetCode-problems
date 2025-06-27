// Used getline function
// getline(stream, str, delim);
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root); 
        while( q.size() ){
            TreeNode* node = q.front();
            q.pop();
            if(!node)    s += "#,";
            else{
                s += to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str;
        getline(s,str,',');
        if( str == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if( node ){
                if( !getline(s,str,',') ) break;
                if( str=="#" )    node->left = NULL;
                else{
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
                if( !getline(s,str,',') ) break;
                if(str=="#")    node->right = NULL;
                else{
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};