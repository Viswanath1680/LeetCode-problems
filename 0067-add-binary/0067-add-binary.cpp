class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        while (a.length() < b.length()) a += '0';
        while (b.length() < a.length()) b += '0';

        string ans;
        int carry = 0;

        for (int i = 0; i < a.length(); i++) {
            int bitA = a[i] - '0';  
            int bitB = b[i] - '0';  
            int sum = bitA + bitB + carry;

            ans += (sum % 2) + '0'; 
            carry = sum / 2;        
        }

        if (carry) ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
