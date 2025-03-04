class Solution {
public:
    int digitsCount(int k){
        int ans = 0;
        while(k){
            k /= 10;
            ans++;
        }
        return ans;
    }

    vector<int> addToArrayForm(vector<int>& arr, int k) {
        reverse(arr.begin(), arr.end());

        int digits_count = digitsCount(k);
        while( arr.size() < digits_count )  arr.push_back(0);

        int carry = 0;
        for( int i = 0; i < arr.size(); i++ ){
            int sum = arr[i] + k % 10 + carry;
            arr[i] = sum % 10;
            carry = sum / 10;
            k /= 10;
        }
        if( carry ) arr.push_back(1);
        reverse(arr.begin(), arr.end());
        return arr;
    }
};