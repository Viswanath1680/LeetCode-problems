// Build a decision tree
// Only 3 decision for each node, as the number can go upto 255 only
class Solution {
public:
    bool valid(string temp){
        if(temp.size() > 3 || temp.size() == 0) return false;
        if(temp.size() > 1 && temp[0] == '0')   return false;
        if(temp.size() && stoi(temp) > 255) return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        int n = s.length();
        if( n > 12 )   return answer;

        auto backtrack = [&](auto& self, string output, int ind, int dots_count) -> void{
            if( dots_count == 3 ){
                if( valid( s.substr(ind) ) )    answer.push_back( output + s.substr(ind));
                return;
            }
            int size = s.size();
            for( int i = ind; i < min(ind+3, size); i++ ){
                if( valid(s.substr(ind, i-ind+1)) ){
                    output += s[i];
                    output += ".";
                    self(self, output, i+1, dots_count+1);
                    output.pop_back();
                }
            }
        };

        string output;
        backtrack(backtrack, output, 0, 0);
        return answer;
    }
};