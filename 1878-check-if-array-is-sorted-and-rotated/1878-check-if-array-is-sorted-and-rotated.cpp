class Solution {
public:
    // Sliding Window technique. First append arr to arr itself. Check in the consequent n-sized window if any window satisfies sorted condition.
    bool check(vector<int>& arr) {
        int n = arr.size();
        arr.insert(arr.end(), arr.begin(), arr.end());
        int conditions = 0;
        for( int i = 0; i < n-1; i++ ){
            if( arr[i] <= arr[i+1] )     conditions++;
        }
        if( conditions == n-1 ) return true;

        for( int i = n-1; i < arr.size()-1; i++ ){
            if( arr[ i-n+1 ] <= arr[i-n+2] )   conditions--;
            if( arr[i] <= arr[i+1] )    conditions++;
            if( conditions == n-1 ) return true;
        }
        return false;
    }
};