class Solution {
public:
    void recursive( vector<string>&ans, string &temp, int len, int n, bool isZero ){
        if( len == n ){
            ans.emplace_back(temp);
            return;
        }
        if( isZero ){
            temp.append("1");
            recursive(ans, temp, len+1, n, false);
            temp.pop_back();
            return;
        }
        string temp_copy = temp;
        temp.append("1");
        recursive(ans, temp, len+1, n, false);
        // temp_copy = temp;
        temp.pop_back();
        temp.append("0");
        // temp_copy.append("0");
        recursive(ans, temp, len+1, n, true);
        temp.pop_back();
    }

    vector<string> validStrings(int n) {
        vector<string>ans;
        string temp = "";
        recursive( ans, temp, 0, n, false);
        return ans;
    }
};