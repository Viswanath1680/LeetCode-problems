class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length())    return false;
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));

        auto recursive = [&](auto& self, int i, int j) -> bool {
            if (cache[i][j] != -1)    return cache[i][j];
            if (i == m && j == n)    return cache[i][j] = true;

            bool b1 = false, b2 = false;
            if (i != m && s1[i] == s3[i + j])    b1 = self(self, i + 1, j);
            if (j != n && s2[j] == s3[i + j])    b2 = self(self, i, j + 1);
            return cache[i][j] = (b1 || b2);
        };

        return recursive(recursive, 0, 0);
    }
};