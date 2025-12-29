class Solution {
public:
    unordered_map<string, vector<char>> ump;
    unordered_set<string> bad;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) {
            ump[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }

    bool dfs(const string& layer) {
        if (layer.size() == 1) return true;
        if (bad.count(layer)) return false;

        string nextLayer;
        if (buildNext(0, layer, nextLayer)) return true;

        bad.insert(layer);
        return false;
    }

    bool buildNext(int idx, const string& layer, string& nextLayer) {
        if (idx == layer.size() - 1) {
            return dfs(nextLayer);
        }

        string key = layer.substr(idx, 2);
        if (!ump.count(key)) return false;

        for (char c : ump[key]) {
            nextLayer.push_back(c);
            if (buildNext(idx + 1, layer, nextLayer)) return true;
            nextLayer.pop_back();
        }

        return false;
    }
};
