using pipi = pair<int, pair<int, int>>; // {effort, {r, c}}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        priority_queue<pipi, vector<pipi>, greater<pipi>> pq;
        
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            auto [curr_effort, pos] = pq.top(); pq.pop();
            int r = pos.first, c = pos.second;
            
            if (r == m - 1 && c == n - 1) return curr_effort;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                
                int new_effort = max(curr_effort, abs(heights[nr][nc] - heights[r][c]));
                
                if (new_effort < effort[nr][nc]) {
                    effort[nr][nc] = new_effort;
                    pq.push({new_effort, {nr, nc}});
                }
            }
        }
        
        return 0; // doesn't hit this
    }
};
