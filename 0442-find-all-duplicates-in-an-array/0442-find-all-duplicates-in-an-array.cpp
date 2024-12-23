class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        for( int i = 0; i < n; i++ ){
            int real_index = arr[i] - 1;
            if( arr[real_index] != arr[i] ){
                swap( arr[i], arr[real_index] );
                i--;
            }
        }
        // for( auto it : arr )    cout << it << " ";
        vector<int>answer;
        for( int i = 0; i < n; i++ ){
            if( i != arr[i]-1 ) answer.emplace_back( arr[i] );
        }
        return answer;
    }
};