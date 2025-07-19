// Trie idea:
// Split the path (like /a/b/c) into ["a", "b", "c"].
// Build the Trie:
// While inserting, if we find a node already marked as end (isEnd = true), we stop.
// DFS through Trie to collect only the folders marked as isEnd.

struct TrieNode {
    unordered_map<string, TrieNode*> children;
    bool isEnd = false;
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(const vector<string>& path) {
        TrieNode* node = root;
        for (const string& part : path) {
            if (node->isEnd) return; // Already a parent folder, skip inserting
            if (!node->children.count(part))
                node->children[part] = new TrieNode();
            node = node->children[part];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode* node, vector<string>& path, vector<string>& result) {
        if (node->isEnd) {
            string folder = "";
            for (const string& part : path)
                folder += "/" + part;
            result.push_back(folder);
            return; // Do NOT go deeper into subfolders
        }

        for (auto& [name, child] : node->children) {
            path.push_back(name);
            dfs(child, path, result);
            path.pop_back();
        }
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        // Insert all folders into Trie
        for (const string& f : folder) {
            vector<string> parts;
            size_t pos = 1; // skip the first '/'
            while (pos < f.size()) {
                size_t next = f.find('/', pos);
                if (next == string::npos) next = f.size();
                parts.push_back(f.substr(pos, next - pos));
                pos = next + 1;
            }
            insert(parts);
        }
        vector<string> result, path;
        dfs(root, path, result);
        return result;
    }
};