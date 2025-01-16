class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        long long int xor_val = 0;
        int n = arr.size();
        for( int i = 0 ; i < n ; i ++)
        	xor_val = xor_val ^ arr[i];
        long long int xor_copy = xor_val;
        xor_val = xor_val & ( xor_val - 1);
        xor_val = xor_val ^ xor_copy; 
        int a = 0 , b = 0;
        for( int i = 0 ; i < n ; i ++){
            if( arr[i] & xor_val )
                a = a ^ arr[i];
            else
                b = b ^ arr[i];
        }
        vector<int> ans = { a , b };
        return ans;
    }  
};