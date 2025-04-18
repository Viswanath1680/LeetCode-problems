class Solution {
public:
    // Iterative approach
    string countAndSay(int n) {
        if( n == 1 )    return "1";
        string prev = "1", curr = "";
        for( int p = 2; p <= n; p++ ){
            curr = "";
            int i = 0, s = prev.length();
            while( i < s ){
                int count = 0;
                char c = prev[i];
                while( i < s && c == prev[i] ){
                    count++;
                    i++;
                }
                curr += to_string(count);
                curr += c;
            }
            prev = curr;
        }
        return curr;
    }
};