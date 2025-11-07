// Collect every component. Let it's size be s. It needs only s-1 edges to stay connected. Remaining are excess and can be used for connecting with other components. 
// How to know number of edges present in a connected component? -> No need
// Just find the number of components in the graph. If there are c components, we need c-1 more to make them connected
// This code finds numComponents using Union Find by size
class Solution {
private:
    vector<int> parent, size;
public:
    int findParent(int u){
        if( u != parent[u] )
            parent[u] = findParent(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v){
        int pu = findParent(u), pv = findParent(v);
        if( pu == pv )  return false;   // already connected

        if( size[pu] > size[pv] ){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = parent[pv];
        }
        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int csize = connections.size();
        if( csize < n-1 )    return -1;
        parent.resize(n);
        size.resize(n, 1);
        for( int i = 0; i < n; i++ )    parent[i] = i;
        int numComponents = n;
        for( auto edge : connections ){
            int u = edge[0], v = edge[1];
            if( unite(u, v) )   numComponents--;
        }
        return numComponents-1;
    }
};