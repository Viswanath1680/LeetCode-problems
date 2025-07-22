// The time it takes for a message from server i to reach the master and for the reply to return to server i is 2 * distance[i]. Let's call this RTT_i.
// the number of resends before the reply for the first message arrives is (RTT_i - 1) / patience[i]. Let this be num_resends.

// The times at which server i sends messages are:
// 0 (initial message)
// patience[i]
// 2 * patience[i]
// ...
// num_resends * patience[i]
class Solution {
public:
    // no need of minHeap. Simple BFS is enough
    vector<int> dijsktra(vector<vector<int>> &edges, int n){
        vector<vector<int>> adjacencyList(n);
        for( auto edge : edges ){
            adjacencyList[ edge[0] ].emplace_back( edge[1] );
            adjacencyList[ edge[1] ].emplace_back( edge[0] );
        }
        vector<int> distance(n, INT_MAX);
        vector<bool> visited(n, false);
        queue<int> q; // {node}
        distance[0] = 0;
        q.push(0);
        visited[0] = true;
        while( !q.empty() ){
            auto node = q.front(); q.pop();
            for( auto neighbor : adjacencyList[node] ){
                if( visited[neighbor] ) continue;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
        return distance;
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> dist_from_master = dijsktra(edges, n);

        long long max_idle_time = 0;
        for (int i = 1; i < n; ++i) {
            long long rtt_i = 2LL * dist_from_master[i]; // Round-trip time for server i

            long long num_resends = 0;
            // Calculate number of resends before the first reply arrives
            // The first reply arrives at rtt_i.
            // Messages are sent at 0, patience[i], 2*patience[i], ...
            // If rtt_i is a multiple of patience[i], say k*patience[i],
            // then the message sent at (k-1)*patience[i] is the last one that *might* be resent
            // before the reply for the 0th message arrives.
            // If rtt_i is not a multiple, then the last resend is at floor(rtt_i / patience[i]) * patience[i].
            // This can be simplified to (rtt_i - 1) / patience[i] to get the number of resends.
            // For example, if RTT = 4, patience = 2: (4-1)/2 = 1 resend. Sends at 0, 2. Reply at 4.
            // If RTT = 3, patience = 2: (3-1)/2 = 1 resend. Sends at 0, 2. Reply at 3.
            
            if (rtt_i > patience[i]) { // Only resend if RTT is greater than patience
                num_resends = (rtt_i - 1) / patience[i];
            }
            
            long long last_send_time = num_resends * patience[i];

            // The time when the reply for the last sent message arrives at server i
            long long reply_arrival_time = last_send_time + rtt_i;

            max_idle_time = max(max_idle_time, reply_arrival_time);
        }

        // The network becomes idle at max_idle_time + 1
        return static_cast<int>(max_idle_time + 1);
    }
};