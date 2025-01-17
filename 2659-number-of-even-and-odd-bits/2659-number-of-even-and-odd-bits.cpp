class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2, 0);
        bool flag = true;
        while( n ){
            if( n & 1 ){
                flag == true ? ans[0]++ : ans[1]++;
            }
            flag = !flag;
            n >>= 1;
        }
        return ans;
    }
};