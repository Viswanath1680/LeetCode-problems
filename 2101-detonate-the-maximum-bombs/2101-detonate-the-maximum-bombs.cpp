using vvi = vector<vector<int>>;
using vi = vector<int>;
using vll = vector<long long>;
using pi = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using ll = long long;
using ull = unsigned long long;

class Solution {
private:
    ll squaredDist(const vi& b1, const vi& b2) {
        ll dx = (ll)b1[0] - b2[0];
        ll dy = (ll)b1[1] - b2[1];
        return dx * dx + dy * dy;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                ll dist = squaredDist(bombs[i], bombs[j]);
                ll r = (ll)bombs[i][2] * bombs[i][2];

                if (dist <= r)
                    adj[i].push_back(j);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            vector<bool> vis(n, false);
            queue<int> q;

            q.push(i);
            vis[i] = true;
            int cnt = 1;

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        cnt++;
                    }
                }
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
