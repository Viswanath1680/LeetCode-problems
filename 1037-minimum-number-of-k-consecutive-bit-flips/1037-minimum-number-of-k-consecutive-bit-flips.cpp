class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipCount = 0;
        int flipState = 0;
        vector<int> isFlipped(n, 0);
        for (int i = 0; i < n; i++) {
            if (i >= k) flipState ^= isFlipped[i - k];
            if ((nums[i] ^ flipState) == 0) {
                if (i + k > n) return -1;
                flipState ^= 1;
                isFlipped[i] = 1;
                flipCount++;
            }
        }
        return flipCount;
    }
};