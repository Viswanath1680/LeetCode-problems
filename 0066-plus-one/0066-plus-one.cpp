class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse( digits.begin(), digits.end() );
        int i = 0;
        int carry = 1;
        while( i < digits.size() && carry ){
            if( digits[i] < 9 ){
                digits[i] += 1;
                carry = 0;
                
            }
            else{
                digits[i] = 0;
                carry = 1;
            }
            i++;
        }
        if( carry ) digits.emplace_back(1);
        reverse( digits.begin(), digits.end() );
        return digits;
    }
};