class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n-1;
        while( i ){
            if( arr[i] <= arr[i-1] )    i--;
            else    break;
        }
        if( i == 0 ){
            sort( arr.begin(), arr.end() );
            return;
        }
        i--;
        int ind = n-1;
        while( arr[ind] <= arr[i] )    ind--;
        swap( arr[i], arr[ind] );
        sort( arr.begin() + i + 1, arr.end() );
        return;
    }
};