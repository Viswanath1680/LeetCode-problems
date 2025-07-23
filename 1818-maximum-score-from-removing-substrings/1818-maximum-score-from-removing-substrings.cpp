// https://youtu.be/r_3a0oG1VcY?si=W-r3B4BQW1upsPfG
class Solution {
public:
    int removePairs( string& s, string pair, int score ){
        stack<char> st;
        int res = 0;
        for( int i = 0; i < s.length(); i++ ){
            if( s[i] == pair[1] && !st.empty() && st.top() == pair[0] ){
                st.pop();
                res += score;
            }
            else    st.push( s[i] );
        }
        string copy = "";
        while( !st.empty() ){
            copy += st.top();
            st.pop();
        }
        s = copy;
        // cout << s;
        reverse(s.begin(), s.end());
        return res;
    }

    int maximumGain(string s, int x, int y) {
        string pair = x > y ? "ab" : "ba";
        // cout << pair << endl;
        int ans = 0;
        ans += removePairs(s, pair, max(x, y));
        reverse(pair.begin(), pair.end());
        ans += removePairs(s, pair, min(x, y));
        return ans; 
    }
};