// push all elements into min heap
using ln = ListNode*;
class Solution {
public:
    // this should return b -> b's value should be minimum
    struct Comparator{
        bool operator()(const ln& a, const ln& b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ln, vector<ln>, Comparator> minHeap;
        for( auto head : lists )    {
            if( head ) minHeap.push(head);
        }
        ln dummy = new ListNode();
        ln ans = dummy;
        ln curr = ans;
        while( minHeap.size() ){
            auto node = minHeap.top();
            minHeap.pop();
            curr->next = node;
            curr = curr->next;
            node = node->next;
            if( node )  minHeap.push(node);
        }
        return ans->next;
    }
};