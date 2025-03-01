class Solution {
public:
    // Delete all the zero instances in the array while tracking the count of zeroes.
    // After array is done, append that many zeroes to the arr.
    void moveZeroes(vector<int>& arr) {
        int count = 0;
        for( auto it = arr.begin(); it != arr.end();){
            if( *it == 0 ){
                it = arr.erase(it);
                count++;
            }
            else    it++;
        }
        while(count--)  arr.emplace_back(0);
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