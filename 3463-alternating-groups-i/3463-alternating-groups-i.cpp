class Solution {
public:
    // harder version : https://leetcode.com/problems/alternating-groups-ii/description/
    bool checkIfAlternative(vector<int>arr, int i, int j){
        bool ans = true;
        for( int p = i+1; p <= j; p++ ){
            if( arr[p] == arr[p-1] ){
                ans = false;
                break;
            }
        }
        return ans;
    }

    int numberOfAlternatingGroups(vector<int>& colors) {
        int k = 3;
        for( int i = 0; i < k-1; i++ )  colors.push_back(colors[i]);
        int j = 0, mis_match_ind,ans = 0;
        bool is_prev_alternate = true;  // tells if previous window is alternate.
        for( j = 1; j < k; j++ ){
            if( colors[j] == colors[j-1] ){
                is_prev_alternate = false;
                mis_match_ind = j;
                break;
            }
        }
        if( is_prev_alternate ) ans++;
        for( j = k; j < colors.size(); j++ ){
            if( is_prev_alternate ){
                if( colors[j] != colors[j-1] )  ans++;
                else{
                    is_prev_alternate = false;
                    mis_match_ind = j;
                }
            }
            else{
                if( mis_match_ind > (j-k+1) )   continue;
                bool current = checkIfAlternative(colors, j-k+1, j);
                if( current )   ans++;
                is_prev_alternate = current;
            }
        }
        return ans;
    }
};