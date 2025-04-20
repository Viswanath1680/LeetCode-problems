class Solution {
public:
    // The following problem helped me build intuition for this problem
    //  https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

    int numRabbits(vector<int>& arr) {
        unordered_map<int, int> ump;
        int n = arr.size();
        int ans = 0;
        for( int i = 0; i < n; i++){ 
            if( arr[i] == 0 )    ans++;
            else    ump[ arr[i]+1 ]++;
        }
        for( auto it : ump ){
            n = it.first;   // n = 11 in 2nd example case
            int k = it.second;  // k = 3
            if( k % n == 0 )    ans += k;
            else    ans += n*( k/n ) + n;
        }
        return ans;
    }
};