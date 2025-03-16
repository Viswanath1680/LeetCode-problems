class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;
        string ans = "";
        bool isFirst = true;
        while( i < m && j < n ){
            if( isFirst ){
                ans += word1[i];
                i++;
            }
            else{
                ans += word2[j];
                j++;
            }
            isFirst = !isFirst;
        }
        while( i < m )  ans += word1[i++];
        while(j < n)    ans += word2[j++];
        return ans;
    }
};