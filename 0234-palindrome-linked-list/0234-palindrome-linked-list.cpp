class Solution {
public:
    // Reverse the second half and compare.
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

    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while( fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
        }
        auto secondIterator = reverseList(slow), iterator = head;
        while( secondIterator ){
            if( iterator->val != secondIterator->val )  return false;
            iterator = iterator->next;
            secondIterator = secondIterator->next;
        }
        return true;
    }
};