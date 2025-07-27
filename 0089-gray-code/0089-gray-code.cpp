class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> answer;
        vector<string> base = {"0", "1"};

        auto dfs = [&](auto& self, int i) -> vector<string>{
            if( i == 1 ){
                return base;
            }
            auto temp = self(self, i-1);
            vector<string> v;
            for( auto s : temp )
                v.push_back("0" + s);
            for( auto it = temp.rbegin(); it != temp.rend(); it++)
                v.push_back( "1" + *it );
            return v;
        };

        vector<string> binaryCodes = dfs(dfs, n);

        vector<int> result;
        for (const auto& binStr : binaryCodes)
            result.push_back(stoi(binStr, nullptr, 2));

        return result;
    }
};