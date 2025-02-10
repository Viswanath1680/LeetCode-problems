class Solution {
public:
    string clearDigits(string s) {
        while (s.find_first_of("0123456789") != std::string::npos) {
            for (size_t i = 0; i < s.length(); ++i) {
                if (isdigit(s[i])) {
                    for (int j = i - 1; j >= 0; --j) {
                        if (!isdigit(s[j])) {
                            s.erase(i, 1);
                            s.erase(j, 1);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return s;
        }
};