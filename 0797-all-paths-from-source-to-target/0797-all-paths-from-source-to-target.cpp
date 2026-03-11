// simple DFS + Backtrack

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;

        auto backtrack = [&](auto& self, int currnode, vector<int>& path) -> void{
            if( currnode == n-1 ){
                ans.emplace_back(path);
                return;
            }
            for( auto& neighbor : graph[currnode] ){
                path.emplace_back(neighbor);
                self(self, neighbor, path);
                path.pop_back();
            }
        };
        vector<int> path = {0};
        backtrack(backtrack, 0, path);
        return ans;
    }
};