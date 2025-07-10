class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())    return {};
        
        wordList.push_back(beginWord);
        
        unordered_map<string, vector<string>> adjacencyList;
        for (int i = 0; i < wordList.size() - 1; i++) {
            string word = wordList[i];
            for (int j = i + 1; j < wordList.size(); j++) {
                int diff = 0;
                string word2 = wordList[j];
                for (int p = 0; p < word.length(); p++) {
                    if (diff > 1) break; // Early termination
                    diff += (word[p] == word2[p]) ? 0 : 1;
                }
                if (diff == 1) {
                    adjacencyList[word].push_back(word2);
                    adjacencyList[word2].push_back(word);
                }
            }
        }
        
        queue<string> q;
        unordered_map<string, int> distances;
        unordered_map<string, vector<string>> parents;
        
        q.push(beginWord);
        distances[beginWord] = 0;
        bool found = false;
        
        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visited;
            
            while( size-- ) {
                string current = q.front();
                q.pop();
                for (string neighbor : adjacencyList[current]) {
                    if (distances.find(neighbor) == distances.end()) {
                        distances[neighbor] = distances[current] + 1;
                        parents[neighbor].push_back(current);
                        visited.insert(neighbor);
                        if (neighbor == endWord)    found = true;
                    } else if (distances[neighbor] == distances[current] + 1) {
                        parents[neighbor].push_back(current);
                    }
                }
            }
            
            for (string word : visited)    q.push(word);
        }
        
        if (!found)    return {};
        
        vector<string> path;
        set<vector<string>> s;
        backtrack(endWord, beginWord, parents, path, s);
        vector<vector<string>> result;
        for( auto string : s )  result.push_back(string);
        return result;
    }
    
private:
    void backtrack(string word, string beginWord, 
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, set<vector<string>>& result) {
        if (word == beginWord) {
            path.push_back(word);
            vector<string> validPath(path.rbegin(), path.rend());
            result.insert(validPath);
            path.pop_back();
            return;
        }
        
        path.push_back(word);
        for (string parent : parents[word]) {
            backtrack(parent, beginWord, parents, path, result);
        }
        path.pop_back();
    }
};