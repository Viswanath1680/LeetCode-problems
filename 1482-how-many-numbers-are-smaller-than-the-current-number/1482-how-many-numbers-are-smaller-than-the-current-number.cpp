class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& arr) {
        map<int, int> mp;
        vector<int>ans;
        // store frequencies first
        for( auto it : arr )    mp[it]++;
        auto prev = mp.begin();
        // for( auto it : mp ) cout << it.first << " " << it.second << ",";
        // cout << "\n";

        // do prefix sum for frequencies
        for( auto it = std::next(mp.begin()); it != mp.end(); it++){
            it->second += prev->second;
            prev++;
        }
        // for( auto it : mp ) cout << it.first << " " << it.second << ",";
        // cout << "\n";

        // Shift the val of current key to next key.
        auto fwd = mp.rbegin();
        for(auto it = std::next(mp.rbegin()); it != mp.rend(); it++){
            fwd->second = it->second;
            fwd++;
        }
        mp.begin()->second = 0;
        // for( auto it : mp ) cout << it.first << " " << it.second << ",";
        // cout << "\n";
        for( int i = 0; i < arr.size(); i++ ){
            int fq = mp[ arr[i] ];
            ans.emplace_back(fq);
        }
        return ans;
    }
};