class Solution {
public:
    int count(ListNode* head){
        int ans = 0;
        auto it = head;
        while( it ){
            ans++;
            it = it->next;
        }
        return ans;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if( !head || !head->next )  return head;
        int n = count(head);
        k = k % n;
        if( k == 0 )    return head;
        auto curr = head, curr_k = head;
        int copy = k;
        while( copy-- ) curr_k = curr_k->next;
        while( curr_k->next ){
            curr = curr->next;
            curr_k = curr_k->next;
        }
        auto nextptr = curr->next;
        curr->next = nullptr;
        curr_k->next = head;
        head = nextptr;
        return head;
    }
};