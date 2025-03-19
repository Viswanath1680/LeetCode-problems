class Solution {
public:
    string reorganizeString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<char, int> freqMap;
        for( auto it : s )  freqMap[ it ]++;

        priority_queue<pair<int, char>> maxHeap;
        for (auto& pair : freqMap){
            if (pair.second > (s.size() + 1) / 2)   return "";
            maxHeap.push({pair.second, pair.first});
        }

        // while( maxHeap.size() ){
        //     auto pair = maxHeap.top();
        //     cout << pair.first << " " << pair.second << " ";
        //     maxHeap.pop();
        // }

        string ans = "";
        while( maxHeap.size() > 1){
            auto [count1, char1] = maxHeap.top();
            maxHeap.pop();
            auto [count2, char2] = maxHeap.top();
            maxHeap.pop();
            ans += char1;
            ans += char2;

            if( --count1 )   maxHeap.push({count1, char1});
            if( --count2 )   maxHeap.push({count2, char2});
        }
        if( maxHeap.size() ){
            auto [count, ch] = maxHeap.top();
            if( count > 1 )    return "";
            ans += ch;
        }
        return ans;
    }
};