/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for( auto it : nums )   mp[it]++;
        ListNode* prev = nullptr, *curr = head;
        while( curr ){
            if( mp[ curr->val ] ){
                if( prev == nullptr ){
                    curr = curr->next;
                    head = curr;
                }
                else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};