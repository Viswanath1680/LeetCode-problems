class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int>arr(51, 0);
        for( auto it : nums )   arr[ it ]++;
        int ans = 0;
        for( int i = 1; i <= 50; i++ ){
            if( arr[i] == 2 )   ans ^= i;
        }
        return ans;
    }
};