// Add a ways[] array to track number of shortest paths to each node
using ll = long long;
using pi = pair<ll, ll>;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pi>> adjacencyList(n);
        for( auto road : roads ){
            adjacencyList[ road[0] ].push_back( {road[1], road[2]} );
            adjacencyList[ road[1] ].push_back( {road[0], road[2]} );
        }
        vector<ll> distance(n, numeric_limits<ll>::max());
        vector<int> ways(n, 0);
        distance[0] = 0;
        ways[0] = 1;
        priority_queue< pi, vector<pi>, greater<pi> > minHeap;  // {time, node}
        minHeap.push( {0, 0} );
        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top(); minHeap.pop();
            if( time > distance[node] ) continue;
            for (auto [neighbor, weight] : adjacencyList[node]) {
                ll new_distance = time + weight;
                if (new_distance < distance[neighbor]) {
                    distance[neighbor] = new_distance;
                    ways[neighbor] = ways[node];
                    minHeap.push({new_distance, neighbor});
                } else if (new_distance == distance[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};