using pii = pair<int, int>;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>> graph(n);
        for (auto& f : flights)
            graph[f[0]].emplace_back(f[1], f[2]);

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q; // {city, cost}
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            vector<int> temp(dist); // copy current distances

            while (sz--) {
                auto [city, cost] = q.front(); q.pop();

                for (auto& [nei, price] : graph[city]) {
                    if (cost + price < temp[nei]) {
                        temp[nei] = cost + price;
                        q.push({nei, temp[nei]});
                    }
                }
            }

            dist = temp; // only update after this level
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
