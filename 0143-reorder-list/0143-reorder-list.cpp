class Solution {
public:
    // 1. Get the 2nd middle node of the linked list
    // 2. Reverse the second half
    // 3. attach each of them to first half as described.
    
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head, *prev = nullptr;
        while( curr ){
            auto nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if( !head->next )    return ;
        auto slow = head, fast = head;
        while( fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
        }
        // now slow is 2nd middle in case of even count
        auto head2 = reverseList(slow->next);
        slow->next = nullptr;
        auto curr = head, curr2 = head2;
        while( curr2 ){
            ListNode* nextptr1 = curr->next, *nextptr2 = curr2->next;
            curr->next = curr2;
            curr2->next = nextptr1;
            curr = nextptr1;
            curr2 = nextptr2;
        }
        return;
    }
};