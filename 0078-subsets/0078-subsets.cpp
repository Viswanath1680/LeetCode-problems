class Solution {
public:
    void recursive( vector<int>& arr, vector<vector<int>>& answer, vector<int>& temp, int i ){
        int n = arr.size();
        if( i == n ){
            answer.emplace_back( temp );
            return;
        }
        temp.emplace_back( arr[i] );
        recursive( arr, answer, temp, i+1 );
        temp.pop_back();
        recursive(arr, answer, temp, i+1);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int>temp;
        recursive( nums, answer, temp, 0 );
        return answer;
    }
};