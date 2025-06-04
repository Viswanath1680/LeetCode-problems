class Solution {
public:
    string answerString(string word, int numFriends) {
        // max size of answer can be n-numFriends+1
        if( numFriends == 1 )    return word;
        int n = word.size();
        string ans = "";
        for( int i = 0; i < n; i++ ){
            if( i > 0 && word[i] < ans[0] )  continue;
            ans = max(ans, word.substr(i, min(n-numFriends+1, n-i)));
        }
        return ans;
    }
};