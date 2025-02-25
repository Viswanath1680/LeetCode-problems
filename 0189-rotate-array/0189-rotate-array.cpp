class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        int boundary = n - k;
        reverse( arr.begin(), arr.begin() + boundary);
        reverse( arr.begin() + boundary, arr.end() );
        reverse(arr.begin(), arr.end());
    }
};