class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjacencyList(n);
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                if( isConnected[i][j] ) adjacencyList[i].push_back(j);

        vector<bool> visited(n, false);
        auto bfs = [&](int i) -> void{
            visited[i] = true;
            queue<int> q;
            q.push(i);
            while( !q.empty() ){
                auto top = q.front(); q.pop();
                for( auto neighbor : adjacencyList[top] ){
                    if( !visited[neighbor] )    {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        };

        int provinces = 0;
        for( int i = 0; i < n; i++ ){
            if( !visited[i] ){
                provinces++;
                bfs(i);
            }
        }
        return provinces;
    }
};