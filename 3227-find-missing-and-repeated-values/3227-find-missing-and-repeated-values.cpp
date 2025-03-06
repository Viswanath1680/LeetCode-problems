class Solution {
public:
    vector<int> cyclicSort(vector<int> arr){
        for( int i = 0; i < arr.size(); i++ ){
            int actual = arr[i] - 1;
            if( arr[i] != arr[actual] ){
                swap( arr[actual], arr[i] );
                i--;
            }
        }
        vector<int> ans;
        for( int i = 0; i < arr.size(); i++ ){
            if( arr[i] != (i+1) ){
                ans.emplace_back(arr[i]);
                ans.emplace_back(i+1);
                break;
            }
        }
        return ans;
    }

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        int n = grid.size();
        for(auto outer : grid )    for( auto it : outer )   arr.emplace_back(it);
        return cyclicSort(arr);
    }
};