class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s;
        while( head ){
            s += to_string( head->val );
            head = head->next;
        }
        int l = 0, h = s.size()-1;
        while( l < h ){
            if( s[l] != s[h] )  return false;
            l++, h--;
        }
        return true;
    }
};