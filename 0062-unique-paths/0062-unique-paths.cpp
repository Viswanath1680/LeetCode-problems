class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r;
        
        long long ans = 1;
        for (int i = 1; i <= r; i++)
            ans = ans * (n - r + i) / i;
        return ans;
    }

    int uniquePaths(int m, int n) {
        m--, n--;
        return nCr(m+n, m);
    }
};