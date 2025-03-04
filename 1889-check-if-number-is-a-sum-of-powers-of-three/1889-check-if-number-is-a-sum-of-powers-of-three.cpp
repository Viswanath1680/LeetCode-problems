class Solution {
public:
    bool base3(int n){
        while(n){
            int k = n%3;
            if( k == 2 )    return false;
            n = n/3;
        }
        return true;
    }

    bool checkPowersOfThree(int n) {
        return base3(n);
    }
};