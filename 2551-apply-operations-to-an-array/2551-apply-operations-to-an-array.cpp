class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int count = 0;
        for( int i = 0; i < arr.size(); i++ ){
            if( arr[i] != 0 ){
                swap(arr[i], arr[count]);
                count++;
            }
        }
    }

    vector<int> applyOperations(vector<int>& arr) {
        int n = arr.size();
        for( int i = 0; i < n-1; i++ ){
            if( arr[i] == arr[i+1] ){
                arr[i] *= 2;
                arr[i+1] = 0;
            }
        }
        moveZeroes(arr);
        return arr;
    }
};