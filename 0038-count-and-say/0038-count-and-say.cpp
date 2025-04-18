class Solution {
public:
    string RLE(int n){
        if( n == 2 )    return "11";
        if( n == 3 )    return "21";
        string prev = RLE(n-1);
        string ans = "";
        int i = 0, s = prev.length();
        while( i < s ){
            int count = 0;
            char c = prev[i];
            while( i < s && c == prev[i] ){
                count++;
                i++;
            }
            ans += to_string(count);
            ans += c;
        }
        return ans;
    }

    string countAndSay(int n) {
        if( n == 1 )    return "1";
        return RLE(n);
    }
};