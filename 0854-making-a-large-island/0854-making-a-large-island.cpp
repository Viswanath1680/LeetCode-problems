/*
Idea:
Label Islands:

    Use dfs to mark all cells in the same island with a unique ID and calculate the island size.
    Store sizes in a map where keys are IDs and values are sizes.

Flip Each 0:

    For each 0, consider the sizes of its neighboring unique islands (tracked by their IDs).
    Sum their sizes and add 1 (the flipped cell).

Avoid Duplicates:

    Use a set to ensure you don’t count the same island multiple times.
*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int id, vector<vector<int>>& islandId) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = 0;  // Mark the cell as visited
        islandId[i][j] = id;
        return 1 + dfs(grid, i + 1, j, id, islandId) +
                   dfs(grid, i - 1, j, id, islandId) +
                   dfs(grid, i, j + 1, id, islandId) +
                   dfs(grid, i, j - 1, id, islandId);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> islandId(rows, vector<int>(cols, 0));
        unordered_map<int, int> islandSizes;
        int id = 2;  // Start unique IDs from 2
        int maxIslandSize = 0;

        // Step 1: Identify and label all islands with unique IDs
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, id, islandId);
                    islandSizes[id] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    id++;
                }
            }
        }

        // Step 2: Check each `0` to see the potential maximum size by flipping
        vector<int> directions = {1, 0, -1, 0, 1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (islandId[i][j] == 0) {
                    unordered_set<int> seenIslands;
                    int potentialSize = 1;  // Count the flipped cell itself
                    for (int d = 0; d < 4; d++) {
                        int ni = i + directions[d];
                        int nj = j + directions[d + 1];
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && islandId[ni][nj] > 1) {
                            int neighborId = islandId[ni][nj];
                            if (seenIslands.insert(neighborId).second) {  // Avoid duplicate islands
                                potentialSize += islandSizes[neighborId];
                            }
                        }
                    }
                    maxIslandSize = max(maxIslandSize, potentialSize);
                }
            }
        }

        return maxIslandSize;
    }
};
