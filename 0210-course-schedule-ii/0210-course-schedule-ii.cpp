// kahn's algo
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<int> inDegree(numCourses);
        for( auto v : prerequisites ){
            adjacencyList[ v[1] ].emplace_back( v[0] );
            inDegree[v[0]]++;
        }
        queue<int> q;
        for( int i = 0; i < numCourses; i++ )   if( inDegree[i] == 0 )  q.push(i);
        vector<int> topo;
        while( q.size() ){
            auto node = q.front(); q.pop();
            topo.push_back(node);
            for( auto neighbor : adjacencyList[node] ){
                inDegree[neighbor]--;
                if( inDegree[neighbor] == 0 )   q.push(neighbor);
            }
        }
        return ( topo.size() == numCourses ) ? topo : vector<int>();
    }
};