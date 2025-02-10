class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<int> st;
        vector<bool> arr(n, false);
        for( int i = 0; i < n; i++ ){
            if( s[i] - '0' >= 0 && s[i] - '0' <= 9 ){
                int ind = st.top();
                st.pop();
                arr[ind] = true;
                arr[i] = true;
            }
            else    st.push(i);
        }
        string ans = "";
        for( int i = 0; i < n; i++ ){
            if( arr[i] == false )   ans += s[i];
        }
        return ans;
    }
};  