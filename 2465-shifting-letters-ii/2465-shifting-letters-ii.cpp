class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<vector<int>> negativeShifts;
        int n = s.size();
        vector<int> prefix(n+2, 0);
        for( auto v : shifts ){
            if( v[2] == 0 ){
                negativeShifts.push_back(v);
                continue;
            }
            prefix[ v[0] ]++;
            prefix[ v[1] + 1 ]--;
        }
        prefix[0] %= 26;
        for( int i = 1; i <= n+1; i++ )
            prefix[i] = (prefix[i]%26 + prefix[i-1]%26)%26;

        for( int i = 0; i < n; i++ )
            s[i] = ((s[i] - 'a' + prefix[i] + 26) % 26) + 'a';

        if( negativeShifts.size() == 0 )    return s;

        vector<int> suffix(n+2, 0);
        for( auto v : negativeShifts ){
            suffix[ v[0] ]++;
            suffix[ v[1] + 1 ]--;
        }

        suffix[n+1] %= 26;
        for( int i = n; i >= 0; i-- )
            suffix[i] = (suffix[i]%26 + suffix[i+1]%26) % 26;

        for( int i = 0; i < n; i++ )
            s[i] = ((s[i] - 'a' + suffix[i+1] + 26) % 26) + 'a';

        return s;
    }
};
