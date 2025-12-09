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

// using the original and changed vectors, create a graph. we need the shortest distance of each char from one to another inorder to solve the problem
// implies we need to use Floyd Warshall algo, to get all possible pairs shortest paths
class Solution {
public:
    void floydWarshall(vvi &dist) {
        int n = dist.size();
        
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        // k is the intermediate node between i and j
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == 1e8) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vvi adjacencyList(26, vi(26, 1e8));   // a matrix where adjacencyList[i][j] represents i-> j cost
        for( int i = 0; i < original.size(); i++ ){
            int o = original[i] - 'a', c = changed[i] - 'a';
            adjacencyList[o][c] = min(adjacencyList[o][c] , cost[i]); // directed graph between them
        }
        // now find all possible pairs shorted paths
        floydWarshall(adjacencyList);
        ll ans = 0;
        for( int i = 0; i < source.size(); i++ ){
            int s = source[i] - 'a', t = target[i] - 'a';
            if( adjacencyList[s][t] == 1e8 )    return -1;
            ans += adjacencyList[s][t];
        }
        return ans;
    }
};