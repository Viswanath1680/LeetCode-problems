class Solution {
public:
    struct s{
        vector<int> points;
        int priority;

        s(vector<int> pts, int p) : points(pts), priority(p){}
    };

    struct compare{
        bool operator()(const s& a, const s& b){
            return a.priority > b.priority;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<s, vector<s>, compare> pq;

        for( auto pt : points ){
            int a = pt[0], b = pt[1];
            int priority = a * a + b * b;
            pq.push(s(pt, priority));
        }

        vector<vector<int>> ans;
        while( k-- ){
            auto top = pq.top();
            pq.pop();
            ans.emplace_back( top.points );
        }
        return ans;
    }
};