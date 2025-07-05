using pi = pair<int, int>;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if( groupSize == 1 )    return true;
        int n = hand.size();
        if( n % groupSize ) return false;
        unordered_map<int, int> ump;
        for( auto it : hand )   ump[it]++;
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        for( const auto& [key, freq] : ump )    minHeap.push( {key, freq} );
        while( minHeap.size() ){
            int copy = groupSize;
            vector<pi> v;
            auto [base, freq] = minHeap.top();
            minHeap.pop();
            copy--;
            freq--;
            if( freq ) v.push_back( {base, freq} );
            while( copy && minHeap.size() ){
                auto [num, f] = minHeap.top();
                minHeap.pop();
                if( num != base + 1 )   return false;
                base = num;
                f--;
                if( f ) v.push_back( {num, f} );
                copy--;
            }
            if( copy )  return false;
            for( auto pair : v )    minHeap.push(pair);
        }
        return true;
    }
};