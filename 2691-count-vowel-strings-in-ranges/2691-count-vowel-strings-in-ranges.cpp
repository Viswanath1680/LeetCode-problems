class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<char, bool> ump;
        ump['a'] = true;
        ump['e'] = true;
        ump['i'] = true;
        ump['o'] = true;
        ump['u'] = true;
        int n = words.size();
        vector<int> pref(n, 0 );
        for( int i = 0; i < n; i++ ){
            string temp = words[i];
            int k = temp.length();
            if( ump[ temp[0] ] && ump[ temp[k-1] ] )    pref[i] = 1;
        }

        for( int i = 1; i < n; i++ )    pref[i] += pref[i-1];

        vector<int>ans( queries.size(), 0 );
        for( int i = 0; i < queries.size(); i++ ){
            ans[i] = pref[ queries[i][1] ] - (queries[i][0] == 0 ? 0 : pref[queries[i][0]-1]);
        }
        return ans;
    }
};