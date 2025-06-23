class Solution {
public:
    void generateHalf(int pos, int halfLength, string& current, const vector<int>& baseNumbers, vector<string>& result, bool isOdd) {
        if (pos == halfLength) {
            string fullPalindrome = current;
            int mirrorStart = isOdd ? halfLength - 1 : halfLength;
            for (int i = mirrorStart - 1; i >= 0; --i)    fullPalindrome += current[i];
            result.push_back(fullPalindrome);
            return;
        }

        for (int digit : baseNumbers) {
            if (pos == 0 && digit == 0) continue; // not allowing leading zeroes
            current.push_back('0' + digit);
            generateHalf(pos + 1, halfLength, current, baseNumbers, result, isOdd);
            current.pop_back();
        }
    }

    vector<string> generatePalindromes(const vector<int>& baseNumbers, int k) {
        vector<string> result;
        if (k <= 0 || baseNumbers.empty()) return result;

        string current = "";
        int halfLength = (k + 1) / 2;
        bool isOdd = (k % 2 != 0);

        vector<int> sortedBase = baseNumbers;
        sort(sortedBase.begin(), sortedBase.end());
        generateHalf(0, halfLength, current, sortedBase, result, isOdd);
        return result;
    }

    long long convertStringToInt(const string& s, int k) {
        long long num = 0;
        for (char c : s)    num = num * k + (c - '0');
        return num;
    }

    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--])    return false;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long ans = 0;
        vector<int> baseNumbers;
        for (int i = 0; i < k; i++)    baseNumbers.push_back(i);

        int len = 1;
        while (n > 0) {
            auto palindromes = generatePalindromes(baseNumbers, len);
            for (const string& p : palindromes) {
                long long val = convertStringToInt(p, k);
                if (val == 0) continue;

                string base10 = to_string(val);
                if (isPalindrome(base10)) {
                    // cout << val << " ";
                    ans += val;
                    n--;
                    if (n == 0) break;
                }
            }
            len++;
        }
        return ans;
    }
};
