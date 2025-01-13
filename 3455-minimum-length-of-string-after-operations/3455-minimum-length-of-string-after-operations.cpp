class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> ump;
        for( int i = 0; i < s.length(); i++ )   ump[ s[i] ]++;
        int answer = 0;
        for( auto it : ump )   answer += ( it.second % 2 == 1 ? 1 : 2 );
        return answer;
    }
};