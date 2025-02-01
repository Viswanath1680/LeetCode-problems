class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        int n = arr.size();
        if( n == 1 )    return true;
        for( auto& it : arr )   it = it&1;
        for( int i = 0; i < n-1; i++ ){
            if( arr[i] == arr[i+1] )    return false;
        }
        return true;
    }
};