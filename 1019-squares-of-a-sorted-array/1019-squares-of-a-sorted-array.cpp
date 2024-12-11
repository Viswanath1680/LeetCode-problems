class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        int l, r;
        int num = INT_MAX;
        for( int i = 0; i < n; i++ ){
            if( arr[i] * arr[i] < num ){
                num = arr[i] * arr[i];
                l = i;
            }
        }

        r = l+1;
        vector<int>answer;
        while( l >= 0 && r < n ){
            if( abs( arr[l] ) < abs( arr[r] ) ){
                answer.emplace_back( arr[l] * arr[l] );
                l--;
            }
            else{
                answer.emplace_back( arr[r] * arr[r] );
                r++;
            }
        }
        while( l >= 0 )  answer.emplace_back( arr[l] * arr[l--] );
        while( r < n )  answer.emplace_back( arr[r] * arr[r++] );

        return answer;
    }
};