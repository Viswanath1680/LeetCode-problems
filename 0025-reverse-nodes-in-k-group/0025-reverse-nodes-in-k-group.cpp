class Solution {
public:
    pair<ListNode*, ListNode*> reverseList(ListNode* head) {
        if( head == nullptr || head->next == nullptr )  return {nullptr, head};
        ListNode* current = head, *prev = nullptr;
        while( current ){
            auto nextptr = current->next;
            current->next = prev;
            prev = current;
            current = nextptr;
        }
        return {prev, head};
    }

    int count(ListNode* head){
        auto temp = head;
        int ans = 0;
        while( temp ){
            ans++;
            temp = temp->next;
        }
        return ans;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head) return head;

        int totalNodes = count(head);
        int groups = totalNodes / k;

        auto dummy = new ListNode(0);
        dummy->next = head;

        auto prevGroupTail = dummy, curr = head;

        while (groups--) {
            ListNode* groupHead = curr;
            ListNode* groupTail = curr;

            for (int i = 1; i < k; ++i)    groupTail = groupTail->next;

            auto nextGroupHead = groupTail->next;
            groupTail->next = nullptr;

            auto reversed = reverseList(groupHead);
            prevGroupTail->next = reversed.first;
            reversed.second->next = nextGroupHead;
            prevGroupTail = reversed.second;
            curr = nextGroupHead;
        }
        return dummy->next;
    }
};