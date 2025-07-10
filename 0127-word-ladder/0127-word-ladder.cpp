// First find adjacency list of each word
// In adjacency list of a word, store only if difference is 1
// BFS on beginWord
// First occurence of endWord is the shortest length possible

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> adjacencyList;
        for( int i = 0; i < wordList.size()-1; i++ ){
            string word = wordList[i];
            for( int j = i+1; j < wordList.size(); j++ ){
                int diff = 0;
                string word2 = wordList[j];
                for( int p = 0; p < word.length(); p++ ){
                    if( diff > 1 )  continue;
                    diff += ( word[p] == word2[p] ) ? 0 : 1;
                }
                if( diff == 1 ){
                    adjacencyList[word].push_back(word2);
                    adjacencyList[word2].push_back(word);
                }
            }
        }
        queue<string> q;
        unordered_set<string> set;
        q.push( beginWord );
        set.insert( beginWord );
        int level = 0;
        while( q.size() ){
            int n = q.size();
            level++;
            while( n-- ){
                auto temp = q.front(); q.pop();
                set.insert( temp );
                if( temp == endWord )   return level;
                for( auto s : adjacencyList[temp] ) {
                    if( set.find(s) != set.end() )   continue;
                    set.insert( s );
                    q.push( s );
                }
            }
        }
        return 0;
    }
};