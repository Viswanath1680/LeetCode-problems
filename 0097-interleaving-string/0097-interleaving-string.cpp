class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length())    return false;
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));

        auto recursive = [&](auto& self, int i, int j, int prev, int p1, int p2) -> bool {
            if (cache[i][j] != -1)    return cache[i][j];
            if (i == m && j == n)    return cache[i][j] = (abs(p1 - p2) <= 1);

            bool b1 = false, b2 = false;
            if (i != m && s1[i] == s3[i + j]) {
                int newP1 = p1;
                if (prev != 1)    newP1++;
                b1 = self(self, i + 1, j, 1, newP1, p2);
            }
            if (j != n && s2[j] == s3[i + j]) {
                int newP2 = p2;
                if (prev != 2)    newP2++;
                b2 = self(self, i, j + 1, 2, p1, newP2);
            }
            return cache[i][j] = (b1 || b2);
        };

        return recursive(recursive, 0, 0, 0, 0, 0);
    }
};