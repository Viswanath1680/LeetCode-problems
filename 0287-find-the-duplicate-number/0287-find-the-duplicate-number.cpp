class Solution {
public:
    // Linked List cycle detection idea
    int findDuplicate(vector<int>& arr) {
        int slow = 0, fast = 0;
        slow = arr[0], fast = arr[arr[0]];
        while( slow != fast ){
            slow = arr[slow ];
            fast = arr[ arr[ fast ] ];
        }
        int temp = 0;
        while( temp != slow ){
            slow = arr[slow];
            temp = arr[temp];
        }
        return slow;
    }
};