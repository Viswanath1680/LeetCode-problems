class Solution {
public:
    vector<int> kahn(vector<int>& adjacencyList){
        int n = adjacencyList.size();
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (adjacencyList[i] != -1)
                indegree[adjacencyList[i]]++;
        }
        queue<int> q;
        for( int i = 0; i < n; i++ )    if( indegree[i] == 0 )  q.push(i);
        vector<int> toposort;
        while( !q.empty() ){
            auto node = q.front(); q.pop();
            toposort.emplace_back(node);
            auto neighbor = adjacencyList[node];
            if( neighbor == -1 )    continue;
            indegree[neighbor]--;
            if( indegree[neighbor] == 0 )   q.push(neighbor);
        }
        return toposort;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        auto toposort = kahn(edges);
        if( toposort.size() == n )  return -1; // no cycle detected
        
        vector<bool> isOutOfCycle(n, false);
        for (int node : toposort) isOutOfCycle[node] = true;

        vector<bool> visited(n, false);
        int longest = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] || isOutOfCycle[i]) continue;

            vector<int> depth(n, -1); // depth of nodes in this path
            int d = 0;
            int node = i;

            while (node != -1 && !visited[node]) {
                visited[node] = true;
                depth[node] = d++;
                int next = edges[node];

                if (next != -1 && depth[next] != -1) {
                    // found a cycle
                    longest = max(longest, d - depth[next]);
                    break;
                }

                node = next;
            }
        }


        return longest;
    }
};