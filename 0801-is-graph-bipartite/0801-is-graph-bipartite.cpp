// My Initial thought was to detect any odd cycle in the graph and return 
// is biparted accordingly. But apparently, obtaining cycle length in a graph
// is NP-complete. So my thought was the converse.
// We can tell if a graph has an odd cycle by using isBipartite() function, and 
// not the reverse

// https://www.geeksforgeeks.org/dsa/check-graphs-cycle-odd-length/


// DFS approach
class Solution {
public:
    bool isBipartite(vector<vector<int>>& adjacencyList) {
        int n = adjacencyList.size();

        vector<int> visited(n, -1);
        auto dfs = [&](auto& self, int i, int parent, int color) -> bool{
            if( visited[i] != -1 ){
                // if( visited[i] != color )   return false;
                // return true;
                return (visited[i] == color);
            }
            visited[i] = color;
            for( auto node : adjacencyList[i] ){
                if( node == parent )    continue;
                if( self(self, node, i, 1 - color) == false )  return false;
            }
            return true;
        };

        // for all the components
        for( int i = 0; i < n; i++ ){
            if( visited[i] == -1 ){
                bool val = dfs(dfs, i, -1, 0);
                if( !val )  return false;
            }
        }
        return true;
    }
};