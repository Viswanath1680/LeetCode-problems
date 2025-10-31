// use cycle sort

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& arr) {
        int n = arr.size(), i =0;
        while( i < n ){
            if( i == arr[i] )   i++;
            else{
                int correct_ind = arr[i];
                if( arr[i] == arr[correct_ind] )    i++;
                else    swap(arr[i], arr[correct_ind]);
            }
        }
        vector<int> ans;
        for( int i = 0; i < n; i++ )
            if( arr[i] != i )   ans.emplace_back(arr[i]);
        return ans;
    }
};