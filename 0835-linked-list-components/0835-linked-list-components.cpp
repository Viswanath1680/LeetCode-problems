class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int components = 0;
        auto curr = head;
        unordered_set<int> s( nums.begin(), nums.end() );
        while( curr ){
            bool isaComponent = false;
            while( curr && s.find( curr->val ) != s.end() ) {
                isaComponent = true;
                curr = curr->next;
            }
            if( isaComponent ) components++;
            if( curr == nullptr )   break;
            curr = curr->next;
        }
        return components;
    }
};