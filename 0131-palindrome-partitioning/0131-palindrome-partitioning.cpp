class Solution {
public:
    // Jai Neetcode
    bool isPalindrome( string& s ){
        int l = 0, h = s.length() -1;
        while( l <= h ){
            if( s[l] != s[h] )  return false;
            l++;
            h--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> v;
        int n = s.length();

        auto recursive = [&](auto& self, int i, vector<string>& v) -> void{
            if( i == n ){
                ans.emplace_back(v);
                return ;
            }
            string temp;
            for( i; i < n; i++ ){
                temp += s[i];
                if( isPalindrome(temp) ){
                    v.emplace_back(temp);
                    self(self, i+1, v);
                    v.pop_back();
                }
            }
        };

        recursive(recursive, 0, v);
        return ans;
    }
};