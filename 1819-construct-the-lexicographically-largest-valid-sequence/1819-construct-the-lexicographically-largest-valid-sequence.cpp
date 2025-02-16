class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);  // Result sequence
        vector<bool> used(n + 1, false); // Track used numbers
        
        // Helper function for backtracking
        function<bool(int)> backtrack = [&](int pos) {
            // If we've filled the sequence, return true
            if (pos == ans.size()) return true;
            
            // If current position is already filled, skip it
            if (ans[pos] != 0) return backtrack(pos + 1);
            
            // Try placing numbers from n to 1
            for (int num = n; num >= 1; --num) {
                if (used[num]) continue; // Skip if already used
                
                if (num == 1 || (pos + num < ans.size() && ans[pos] == 0 && ans[pos + num] == 0)) {
                    // Place number num at pos and pos + num
                    ans[pos] = num;
                    if (num > 1) ans[pos + num] = num;
                    used[num] = true;
                    
                    // Recur for the next position
                    if (backtrack(pos + 1)) return true;
                    
                    // Backtrack
                    ans[pos] = 0;
                    if (num > 1) ans[pos + num] = 0;
                    used[num] = false;
                }
            }
            
            return false;
        };
        
        backtrack(0); // Start backtracking from position 0
        return ans;
    }
};
