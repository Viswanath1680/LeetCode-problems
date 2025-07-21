using pi = pair<int, int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pi>> adjacencyList(n);    // {node, distance}
        for( auto time : times )
            adjacencyList[ time[0] - 1 ].push_back( {time[1]-1, time[2]} );

        vector<int> time(n, INT_MAX);
        time[k-1] = 0;
        priority_queue< pi, vector<pi>, greater<pi> > minHeap;  // {distance, node}
        minHeap.push( {0, k-1} );
        while( !minHeap.empty() ){
            auto [d, node] = minHeap.top(); minHeap.pop();
            for( auto [neighbor, weight] : adjacencyList[node] ){
                int new_dist = weight + d;
                if( new_dist < time[neighbor] ){
                    minHeap.push( {new_dist, neighbor} );
                    time[neighbor] = new_dist;
                }
            }
        }
        int maxTime = 0;
        for( auto t : time ){
            if( t == INT_MAX )  return -1;
            maxTime = max(maxTime, t);
        }
        return maxTime;
    }
};