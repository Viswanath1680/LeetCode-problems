class Solution {
public:
    pair<char, char> findDiffChars(string s1, string s2){
        int len = min(s1.size(), s2.size());
        for (int i = 0; i < len; ++i) {
            if (s1[i] != s2[i])    return {s1[i], s2[i]};
        }
        return {'\0', '\0'};
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        for (int i = 1; i < n; i++) {
            // checking invalid prefix cases, like [abc, ab]. Basically this test case is invalid.
            if (words[i-1].size() > words[i].size() &&
                words[i-1].substr(0, words[i].size()) == words[i]) {
                return false;
            }
        }

        unordered_map<char, int> ump;
        for( int i = 0; i < order.size(); i++ ) ump[ order[i] ] = i;
        for( int i =  1; i < n; i++ ){
            auto [a, b] = findDiffChars(words[i-1], words[i]);
            if( a == '\0' ) continue;
            if( ump[a] > ump[b] )   return false;
        }
        return true;
    }
};