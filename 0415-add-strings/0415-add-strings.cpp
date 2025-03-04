class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        while( num1.size() < num2.size() )  num1 += '0';
        while( num2.size() < num1.size() )  num2 += '0';
        string ans;
        int carry = 0;
        for( int i = 0; i < num1.size(); i++ ){
            int a = num1[i] - '0', b = num2[i] - '0';
            int sum = a + b + carry;
            ans += ( sum % 10 ) + '0';  // adding '0' converts sum%10 into char.
            carry = sum/10;
        }
        if( carry ) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};