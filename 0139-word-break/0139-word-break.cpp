class Solution {
public:
    // Same as Palindrome Partitioning
    bool wordBreak(string target, vector<string>& wordDict) {
        bool ans;
        int n = target.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> ump;

        auto recursive = [&](auto& self, string temp) -> bool{
            if( ump.count(temp) )   return ump[temp];
            if( temp == target ) return true;
            if( temp.length() > target.length() ){
                return ump[temp] = false;
            }
            if( target.starts_with(temp) == false ){
                return ump[temp] = false;
            }
            bool isPossible = false;
            for( auto& s : wordDict ){
                string next = temp + s;
                isPossible = self(self, next);
                if( isPossible )   break;
            }
            ump[temp] = isPossible;
            return isPossible;
        };

        string temp = "";
        return recursive(recursive, temp);
    }
};