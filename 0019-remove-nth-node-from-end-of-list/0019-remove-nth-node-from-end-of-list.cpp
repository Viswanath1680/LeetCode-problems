class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto curr = head, curr_n = head;
        ListNode* prev = nullptr;
        while( n-- )    curr_n = curr_n->next;
        // now gap between curr and curr_n is n
        while( curr_n ){
            prev = curr;
            curr = curr->next;
            curr_n = curr_n->next;
        }
        if( !prev ) return curr->next;
        prev->next = curr->next;
        return head;
    }
};