// check if topo sort is possible
// Kahn's algo
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjacencyList(numCourses);
        for( auto v : prerequisites ){
            inDegree[ v[0] ]++;
            adjacencyList[ v[1] ].emplace_back( v[0] );
        }
        vector<int> topo;
        queue<int> q;
        for( int i = 0 ; i < numCourses; i++ )  
            if( inDegree[i] == 0 )  q.push(i);
        while( !q.empty() ){
            auto node = q.front(); q.pop();
            topo.emplace_back(node);
            for( auto neighbor : adjacencyList[node] ){
                inDegree[neighbor]--;
                if( inDegree[neighbor] == 0 )   q.push(neighbor);
            }
        }
        return topo.size() == numCourses;
    }
};