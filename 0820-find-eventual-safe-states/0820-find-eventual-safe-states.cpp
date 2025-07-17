// To use the topological sort algorithm, we will reverse every edge of the graph. Now, the nodes with indegree 0 become the terminal nodes. After this step, we will just follow the topological sort algorithm as it is.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adjacencyList) {
        int n = adjacencyList.size();
        vector<vector<int>> reverseAdjList(n);
        vector<int> indegree(n);
        for( int node = 0; node < n; node++ ){
            for( auto neighbor : adjacencyList[node]  ){
                reverseAdjList[ neighbor ].emplace_back( node );
                indegree[ node ]++;
            }
        }

        vector<int> topo;
        queue<int> q;
        for( int i = 0; i < n; i++ )    if( indegree[i] == 0 )  q.push( i );
        while( !q.empty() ){
            auto node = q.front(); q.pop();
            topo.push_back( node );
            for( auto neighbor : reverseAdjList[node] ){
                indegree[neighbor]--;
                if( indegree[neighbor] == 0 )   q.push( neighbor );
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};