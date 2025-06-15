class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.length();
        if( n == 0 )    return ans;
        string temp;
        unordered_map<char, vector<string>> ump = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
        };
    
        auto recursive = [&] (auto& self, int i) -> void{
            if( i == n ){
                ans.emplace_back(temp);
                return;
            }
            for( auto c : ump[ digits[i] ] ){
                temp += c;
                self(self, i+1);
                temp.pop_back();
            }
        };

        recursive(recursive, 0);
        return ans;
    }
};