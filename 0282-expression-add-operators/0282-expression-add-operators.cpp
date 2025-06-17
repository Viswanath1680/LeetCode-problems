class Solution {
public:
    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        int n = s.length();
        auto backtrack = [&](auto& self, int i, const string& path, long sum, long prevNum) -> void{
            if (i == n) {
                if (sum == target) ans.push_back(path);
                return;
            }
            string numStr;
            long num = 0;
            for (int j = i; j < n; j++) {
                if (j > i && s[i] == '0') break; // Leading zero number
                numStr += s[j];
                num = num * 10 + s[j] - '0';
                if (i == 0) {
                    self(self,j + 1, path + numStr, num, num); // First number
                } 
                else {
                    self(self, j + 1, path + "+" + numStr, sum + num, num);
                    self(self, j + 1, path + "-" + numStr, sum - num, -num);
                    self(self, j + 1, path + "*" + numStr, sum - prevNum + prevNum * num, prevNum * num);
                }
            }
        };

        backtrack(backtrack, 0, "", 0, 0);
        return ans;
    }
};