class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& arr1, vector<int>& arr2) {
        long long ans = 0;
        sort( arr1.begin(), arr1.end(), greater<int>() );
        sort( arr2.begin(), arr2.end(), greater<int>() );
        // vector<int> row( m, 0 ), col( n, 0 );
        long long row = 1, col = 1, l = 0, r = 0;
        while( l < m-1 && r < n-1){
            if( arr1[l] > arr2[r] ){
                ans += (long long)row * arr1[l];
                col ++, l++;
            }
            else{
                ans += (long long)col * arr2[r];
                row++, r++;
            }
        }
        while( l < m-1 ){
            ans += (long long)row * arr1[l];
            col ++, l++;
        }
        while( r < n-1 ){
            ans += (long long)col * arr2[r];
            row++, r++;
        }
        return ans;
    }
};