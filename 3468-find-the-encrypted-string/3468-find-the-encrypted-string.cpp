class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        k = k % n;
        string temp = s.substr(0,k);
        for( int i = 0 ; i < n - k ; i++){
            s[i] = s[ i+k ];
        }
        for( int i = n-k ; i < n ; i++)
            s[i] = temp[i-n+k];
        return s;
    }
};