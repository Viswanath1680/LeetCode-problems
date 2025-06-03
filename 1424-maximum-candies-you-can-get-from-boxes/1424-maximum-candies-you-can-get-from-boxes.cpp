class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        unordered_map<int, bool> visited;
        unordered_set<int> foundBoxes; // you only have access to boxes that are in foundBoxes list
        queue<int> q;
        for( auto box : initialBoxes ){
            foundBoxes.insert(box);
            if( status[box] ){
                q.push(box);
                visited[box] = true;
                ans += candies[box];
            }
        }

        while( q.size() ){
            auto box = q.front();
            q.pop();
            for( auto insideBox : containedBoxes[box] ){
                foundBoxes.insert(insideBox);
                if( status[insideBox] == 1 && (visited.find(insideBox) == visited.end() ) ){
                    q.push(insideBox);
                    visited[insideBox] = true;
                    ans += candies[insideBox];
                }
            }

            for( auto key : keys[box] ){
                status[key] = 1;
                if(foundBoxes.count(key) && (visited.find(key) == visited.end()) ){
                    q.push(key);
                    visited[key] = true;
                    ans += candies[key];
                }
            }
        }

        return ans;        
    }
};