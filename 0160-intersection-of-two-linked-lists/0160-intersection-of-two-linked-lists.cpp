class Solution {
public:
    int count(ListNode* head){
        int ans = 0;
        auto curr = head;
        while( curr ){
            ans++;
            curr = curr->next;
        }
        return ans;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = count(headA), n = count(headB);
        auto diff = abs(n-m);
        auto c1 = headA, c2 = headB;
        if( m < n ){
            while( diff-- ) c2 = c2->next;
        }
        else    while(diff--)   c1 = c1->next;
        while( c1 != c2 )   c1 = c1->next, c2 = c2->next;
        return c1;
    }
};