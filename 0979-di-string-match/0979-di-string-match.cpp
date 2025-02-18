class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int n = s.size();
        stack<int> st;
        for( int i = 0; i <= n; i++ ){
            st.push(i);
            if( s[i] == 'I' ){
                while( st.size() ){
                    int top = st.top();
                    st.pop();
                    ans.emplace_back(top);
                }
            }
        }
        while( st.size() ){
            int top = st.top();
            st.pop();
            ans.emplace_back(top);
        }
        return ans;
    }
};