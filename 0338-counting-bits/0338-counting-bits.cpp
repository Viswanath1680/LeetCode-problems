class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1, 0);
        if( n == 0 )    return ans;
        ans[1] = 1;
        for( int i = 2; i <= n; i++)    ans[i] = i % 2 + ans[i/2];
        return ans;
    }
};