class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        int n = pattern.size();
        stack<int> st;
        for( int i = 0; i <= n; i++ ){
            st.push(i+1);
            if( pattern[i] == 'I' ){
                while( st.size() ){
                    int top = st.top();
                    st.pop();
                    ans += to_string(top);
                }
            }
        }
        while( st.size() ){
            int top = st.top();
            st.pop();
            ans += to_string(top);
        }
        return ans;
    }
};