class Solution {
public:
    bool isSelfDigit( int n ){
        int copy = n;
        while( copy ){
            int k = copy % 10;
            if( k == 0 || n % k ) return false;
            copy /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if( isSelfDigit(i) )    ans.emplace_back(i);
        }
        return ans;
    }
};