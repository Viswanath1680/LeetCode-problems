class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int maxBalance = (m + n - 1) / 2;
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxBalance + 1, -1)));

        vector<vector<int>> drns = {{1, 0}, {0, 1}};

        auto recursive = [&](auto& self, int i, int j, int balance) -> bool {
            if (i < 0 || i == m || j < 0 || j == n) return false;

            balance += (grid[i][j] == '(' ? 1 : -1);
            if (balance < 0 || balance > maxBalance) return false;
            if (i == m - 1 && j == n - 1) return balance == 0;
            if (memo[i][j][balance] != -1) return memo[i][j][balance];
            for (auto& d : drns) {
                int ni = i + d[0], nj = j + d[1];

                if (self(self, ni, nj, balance)) return memo[i][j][balance] = true;
            }

            return memo[i][j][balance] = false;
        };

        return recursive(recursive, 0, 0, 0);
    }
};