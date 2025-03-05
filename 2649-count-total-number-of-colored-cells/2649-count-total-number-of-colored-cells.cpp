class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        ans += ( long long ) ( n ) * n;
        ans += (long long ) ( n-1 )* (n-1) ;
        return ans;
    }
};