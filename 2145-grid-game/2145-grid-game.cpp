class Solution {
public:
    #define ll long long
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        vector<ll> pref1(m), pref2(m);

        pref1[0] = grid[0][0];
        pref2[0] = grid[1][0];

        for (int i = 1; i < m; i++) {
            pref1[i] = pref1[i - 1] + grid[0][i];
            pref2[i] = pref2[i - 1] + grid[1][i];
        }

        ll result = LLONG_MAX;
        for (int i = 0; i < m; i++) {
            ll top = (i == m - 1) ? 0 : pref1[m - 1] - pref1[i];
            ll bottom = (i == 0) ? 0 : pref2[i - 1];
            result = min(result, max(top, bottom));
        }

        return result;
    }
};