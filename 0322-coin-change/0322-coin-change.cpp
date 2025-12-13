// Try BFS. The first instance where you get zero is the answer
// consider a queue and push {target, till_now_coins}
// in the next iteration, go through the coins array and subtract every coin denomination from the target and increase the till_now_coins by 1
// to avoid redundancy, store the target in a dp. If seen this target already, just skip it. Cause this target is already acheived by a lower number of coins
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<bool> isSeen( amount+1, false );
        queue<pair<int, int>> q;
        q.push( {amount, 0} );

        while( !q.empty() ){
            auto [target, count] = q.front();   q.pop();
            if( target == 0 )   return count;
            for( auto& coin : coins ){
                int new_target = target - coin;
                if( new_target < 0 )    continue;
                if( isSeen[new_target] )    continue;
                // if( new_target == 0 )   return ( count + 1 );
                isSeen[new_target] = true;
                q.push( {new_target, count+1} );
            }
        }

        // not acheived the sum
        return -1;
    }
};