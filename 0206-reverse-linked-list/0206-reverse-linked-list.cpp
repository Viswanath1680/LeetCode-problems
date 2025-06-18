class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if( head == nullptr || head->next == nullptr )  return head;
        ListNode* current = head, *prev = nullptr;
        while( current ){
            auto nextptr = current->next;
            current->next = prev;
            prev = current;
            current = nextptr;
        }
        return prev;
    }
};