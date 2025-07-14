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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        auto curr = head, dummy = new ListNode();
        auto dummy_ptr = dummy;
        while( curr ){
            auto temp = curr->next;
            int sum = 0;
            while( temp && temp->val != 0 ){
                sum += temp->val;
                temp = temp->next;
            }
            if( temp ){
                dummy_ptr->next = new ListNode(sum);
                dummy_ptr = dummy_ptr->next;
            }
            curr = temp;
        }
        return dummy->next;
    }
};