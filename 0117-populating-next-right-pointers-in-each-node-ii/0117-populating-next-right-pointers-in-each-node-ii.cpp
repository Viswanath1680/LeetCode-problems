/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if( root == nullptr )   return root;
        list<Node*> l;
        l.push_back(root);
        Node* prev, *current;
        while( l.size() ){
            int n = l.size();
            if( n == 1 ){
                Node* it = l.front();
                l.pop_front();
                if( it->left )  l.push_back(it->left);
                if( it->right ) l.push_back(it->right);
            }
            else{
                prev = l.front();
                l.pop_front();
                if( prev->left )    l.push_back(prev->left);
                if( prev->right )   l.push_back(prev->right);
                current = l.front();
                l.pop_front();
                prev->next = current;
                prev = current;
                n -= 2;
                if( prev->left )    l.push_back(prev->left);
                if( prev->right )   l.push_back(prev->right);
                while( n ){
                    current = l.front();
                    l.pop_front();
                    prev->next = current;
                    prev = current;
                    if( prev->left )    l.push_back(prev->left);
                    if( prev->right )   l.push_back(prev->right);
                    n--;
                }
            }
        }
        return root;
    }
};