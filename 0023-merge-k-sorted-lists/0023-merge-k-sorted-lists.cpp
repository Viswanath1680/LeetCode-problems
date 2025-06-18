// Idea by Ravi Kiran. Push all the heads to heap rather than k pointers

class Solution {
public:
    struct comparator {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);  // dummy node
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
        
        for (auto node : lists)    if (node)    pq.push(node);

        ListNode* temp = head;
        while ( pq.size() ) {
            ListNode* node = pq.top();
            pq.pop();
            temp->next = node;
            temp = temp->next;
            if (node->next)    pq.push(node->next);
        }
        return head->next;
    }
};