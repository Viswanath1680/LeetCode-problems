// This is a directed graph where every node has at most one outgoing edge
// Basically getting the longest cycle in the graph is the answer
// Applying kahn algo to the will split the numbers into two sets, either a number belongs to a cycle(which falls into unvisited set ) or it doesn't. Because, we remove the nodes with 0 indegree in every iteration of kahn and the nodes that belong to a cycle won't become visited.
class Solution {
public:
vector<vector<int>> adjacencyList;

    // whole point of this function is to remove nodes that do not belong to any cycle
    vector<bool> kahn( vector<int>& arr ){
        int n = arr.size();
        vector<bool> BelongsToCycle(n, true);   // initially every node belongs to cycle. We gradually remove the nodes that aren't
        adjacencyList.resize(n);
        vector<int> inDegree(n, 0);
        for( int i = 0; i < n; i++ ){
            adjacencyList[ i ].emplace_back( arr[i] );  // index i points to index arr[i]
            inDegree[arr[i]]++;
        }
        queue<int> q;
        for( int i = 0; i < n; i++ )    if( inDegree[i] == 0 )  q.push(i);
        while( !q.empty() ){
            int node = q.front();   q.pop();
            BelongsToCycle[node] = false;
            for( auto neighbor : adjacencyList[node] ){
                inDegree[ neighbor ]--;
                if( inDegree[neighbor] == 0 )   q.push( neighbor );
            }
        }
        return BelongsToCycle;
    }

    int arrayNesting(vector<int>& arr) {
        int n = arr.size();
        auto BelongsToCycle = kahn(arr);
        vector<bool> isVisited(n, false);
        // now make every non-cycle node visited cause we don't need them anymore
        for( int i = 0; i < n; i++ )    if( BelongsToCycle[i] == false )    isVisited[i] = true;

        auto visitCycle = [&](auto& self, int i) -> int{
            if( isVisited[i] ) return 0;
            isVisited[i] = true;
            return 1 + self(self, adjacencyList[i][0]); // there will be only 1 element anyways
        };

        int max_cycle_len = 1;
        for( int i = 0; i < n; i++ ){
            if( !isVisited[i] ){
                max_cycle_len = max( max_cycle_len, visitCycle(visitCycle, i) );
            }
        }
        return max_cycle_len;
    }
};