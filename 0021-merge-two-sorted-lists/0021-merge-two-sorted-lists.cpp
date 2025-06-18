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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if( !list1 )    return list2;
        if( !list2 )    return list1;
        auto val = min(list1->val, list2->val);
        if( list1->val == val ) list1 = list1->next;
        else    list2 = list2->next;
        ListNode* head = new ListNode(val);
        auto curr = head;
        while( list1 && list2 ){
            auto val = min(list1->val, list2->val);
            if( list1->val == val ) list1 = list1->next;
            else    list2 = list2->next;
            auto temp = new ListNode(val);
            curr->next = temp;
            curr = temp;
        }
        while( list1 ){
            auto temp = new ListNode(list1->val);
            curr->next = temp;
            curr = temp;
            list1 = list1->next;
        }
        while(list2){
            auto temp = new ListNode(list2->val);
            curr->next = temp;
            curr = temp;
            list2 = list2->next;
        }
        return head;
    }
};