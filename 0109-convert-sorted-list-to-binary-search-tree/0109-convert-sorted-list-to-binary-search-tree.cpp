/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct( vector<int>&arr, int l, int r ){
        if( l > r )  return nullptr;
        int n = l + r;
        int midVal = arr[ n/2 ];
        TreeNode* mid = new TreeNode(midVal);
        if( l == r )    return mid;
        mid->left = construct(arr, l, n/2-1 );
        mid->right = construct(arr, n/2 + 1, r);
        return mid;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while( head ){
            arr.emplace_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        TreeNode* root = nullptr;
        if( n == 0 )    return root;
        int rootVal = arr[n/2];
        root = new TreeNode(rootVal);
        root->left = construct(arr, 0, n/2 - 1);
        root->right = construct(arr, n/2+1, n-1 );
        return root;
    }
};