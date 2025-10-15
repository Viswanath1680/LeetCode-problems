// Easier version of the problem: https://leetcode.com/problems/longest-repeating-character-replacement/description/
// we can atmost have k zeroes in our sliding window.

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = 0, ans = 0;
        int zeroes_seen = 0;
        while( r < n ){
            if( arr[r] == 0 ){
                zeroes_seen++;
                while( zeroes_seen > k ){
                    if( arr[l] == 0 )   zeroes_seen--;
                    l++;
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};