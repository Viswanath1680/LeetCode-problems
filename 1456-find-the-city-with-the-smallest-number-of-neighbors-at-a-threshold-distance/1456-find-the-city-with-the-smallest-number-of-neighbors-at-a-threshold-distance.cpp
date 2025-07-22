// Use Floyd warshal algorithm to get minimum distance between two cities
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for( auto edge : edges ){
            int u = edge[0], v = edge[1], weight = edge[2];
            distance[u][v] = weight;
            distance[v][u] = weight;
        }
        for( int k = 0; k < n; k++ ){
            for( int start = 0; start < n; start++ ){
                for( int end = 0; end < n; end++ ){
                    if( start == end ){
                        distance[start][end] = 0;
                        continue;
                    }
                    if( k == start || k == end )    continue;
                    if( distance[start][k] == INT_MAX || distance[k][end] == INT_MAX )  continue;
                    int new_dist = distance[start][k] + distance[k][end];
                    if( new_dist < distance[start][end] )   distance[start][end] = new_dist;
                }
            }
        }
        // Floyd warshal done
        int minCitiesCovered = INT_MAX, ansCity;
        for( int i = 0; i < n; i++ ){
            int tempCitiesCovered = 0;
            for( int j = 0; j < n; j++ ){
                if( j == i )    continue;   // ignore the same city.
                if( distance[i][j] <= distanceThreshold )   tempCitiesCovered++;
            }
            if( minCitiesCovered >= tempCitiesCovered ){
                minCitiesCovered = tempCitiesCovered;
                ansCity = i;
            }
        }
        return ansCity;
    }
};