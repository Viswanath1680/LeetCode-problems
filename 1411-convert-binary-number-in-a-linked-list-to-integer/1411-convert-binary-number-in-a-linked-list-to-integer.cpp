class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        auto curr = head;
        while( curr ){
            ans = (ans << 1) + curr->val;
            curr = curr->next;
        }
        return ans;
    }
};