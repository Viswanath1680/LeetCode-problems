class Solution {
public:
    void recursion(int l, int r, vector<string>& ans, string& temp){
        if( l < 0 || r < 0 )    return ;
        if( l == 0 && r == 0 )    {
            ans.emplace_back(temp);
            return;
        }
        temp += '(';
        recursion(l-1, r, ans, temp);
        temp.pop_back();
        if( l < r )    {
            temp += ')';
            recursion(l, r-1, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        recursion(n, n, ans, temp);
        return ans;
    }
};