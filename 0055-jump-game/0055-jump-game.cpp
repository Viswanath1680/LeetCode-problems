class Solution {
public:
    bool canJump(vector<int>& arr) {
        int maxJump = arr[0], n = arr.size();
        for( int i = 1; i < n; i++){
            if( maxJump >= i ){
                maxJump = max(maxJump, i + arr[i]);
            }
        }
        return maxJump >= n-1;
    }
};