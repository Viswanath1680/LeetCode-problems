class Solution {
public:
    bool checkWithZero( vector<int> arr ){
        // Assuming first element is 0
        // Derive the remaining elements. And check if x_n^x_1 == derived[n-1]
        int n = arr.size();
        vector<int>temp(n);
        temp[0] = 0;
        for( int i = 1; i < n; i++ ){
            temp[i] = arr[i-1] ^ temp[i-1];
        }
        return ( (temp[n-1] ^ temp[0]) == arr[n-1] );
    }

    bool checkWithOne(vector<int> arr){
        int n = arr.size();
        vector<int>temp(n);
        temp[0] = 1;
        for( int i = 1; i < n; i++ ){
            temp[i] = arr[i-1] ^ temp[i-1];
        }
        return ( (temp[n-1] ^ temp[0]) == arr[n-1] );
    }

    bool doesValidArrayExist(vector<int>& derived) {
        // base check condition
        int temp_xor = 0;
        for( auto it : derived )    temp_xor ^= it;
        if( temp_xor ) return false;

        bool b1 = checkWithZero( derived );
        if( b1 )    return true;
        bool b2 = checkWithOne( derived );
        return b2;
    }
};