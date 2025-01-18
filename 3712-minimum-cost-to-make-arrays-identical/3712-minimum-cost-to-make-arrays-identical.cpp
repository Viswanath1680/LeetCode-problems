class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
       // if arrays are same
        bool flag = true;
        int n = arr.size();
        for( int i = 0; i < n; i++ ){
            if( arr[i] != brr[i] ){
                flag = false;
                break;
            }
        }
        if( flag )   return 0;

        
        long long ans1 = 0;
        for( int i = 0; i < n; i++ )  ans1 += (long long)abs( arr[i] - brr[i] );
        
        sort( arr.begin(), arr.end() );
        sort( brr.begin(), brr.end() );

        long long ans2 = k;
        for( int i = 0; i < n; i++ )    ans2 += (long long)abs( arr[i] - brr[i] );

        return ans2 < ans1 ? ans2 : ans1;
        
    }
};