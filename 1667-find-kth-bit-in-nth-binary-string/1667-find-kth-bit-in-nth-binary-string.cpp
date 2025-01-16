class Solution {
public:
    
    string reverse_string(string s){
        for( auto & it : s ){
            if( it == '0' ) it = '1';
            else    it = '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }

    char findKthBit(int n, int k) {
        string a = "0", b;
        bool toggle = false;
        while( --n ){
            if( toggle )    a = b + "1" + reverse_string(b);
            else    b = a + "1" + reverse_string(a);
            toggle = !toggle;
        }
        if( !toggle )    return (char)a[k-1];
        return (char)b[k-1];
    }
};