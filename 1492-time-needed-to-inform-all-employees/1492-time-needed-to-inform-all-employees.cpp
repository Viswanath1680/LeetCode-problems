using vvi = vector<vector<int>>;
using vi = vector<int>;
using vll = vector<long long>;
using pi = pair<int, int>;
using vb = vector<bool>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using ll = long long;
using ull = unsigned long long;

// classic BFS approach
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if( n == 1 )    return 0;
        vvi adjacencyList(n);
        for( int i = 0; i < n; i++ ){
            if( manager[i] == -1 )  continue;
            adjacencyList[i].emplace_back( manager[i] );
            adjacencyList[ manager[i] ].emplace_back( i );
        }

        vector<bool> visited(n, false);
        queue<pi> q;    // {id, time taken to get info this id}
        q.push( {headID, 0} );
        visited[headID] = true;
        int ans = 0;
        while( !q.empty() ){
            int n = q.size();
            while( n-- ){
                auto [id, time] = q.front(); q.pop();
                for( auto neighbor : adjacencyList[id] ){
                    if( visited[neighbor] ) continue;
                    int new_time = informTime[id] + time;
                    ans = max(ans, new_time);
                    q.push( {neighbor, new_time} );
                    visited[neighbor] = true;
                }
            }
        }
        return ans;
    }
};