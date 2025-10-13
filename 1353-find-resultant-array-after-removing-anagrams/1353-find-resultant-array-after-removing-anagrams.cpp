using vs = vector<string>;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vs ans;
        ans.emplace_back(words[0]);
        string prev = words[0];
        sort(prev.begin(),prev.end());
        for( int i = 1; i < words.size(); i++ ){
            auto copy = words[i];
            sort(copy.begin(),copy.end());
            if( copy == prev )  continue;
            else    {
                ans.emplace_back(words[i]);
                prev = copy;
            }
        }
        return ans;
    }
};