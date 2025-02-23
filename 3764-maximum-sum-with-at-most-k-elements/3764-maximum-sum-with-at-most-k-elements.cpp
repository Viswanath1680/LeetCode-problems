class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();        
        for (auto& row : grid) {
            sort(row.rbegin(), row.rend());
        }
        // Max-heap to store {value, row_index, column_index}
        priority_queue<tuple<int, int, int>> maxHeap;
    
        for (int i = 0; i < n; ++i) {
            if (limits[i] > 0 && !grid[i].empty()) {
                maxHeap.emplace(grid[i][0], i, 0);
            }
        }
    
        long long sum = 0;
        vector<int> counts(n, 0);
    
        while (k > 0 && !maxHeap.empty()) {
            auto [val, row, col] = maxHeap.top();
            maxHeap.pop();
    
            sum += val;
            counts[row]++;
            k--;
    
            if (col + 1 < grid[row].size() && counts[row] < limits[row]) {
                maxHeap.emplace(grid[row][col + 1], row, col + 1);
            }
        }
    
        return sum;
    }
};