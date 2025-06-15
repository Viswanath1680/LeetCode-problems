class Solution {
public:
    struct Compare{
        bool operator()(const vector<int>& v1, const vector<int>& v2){
            double d1 = sqrt(pow(v1[0], 2) + pow(v1[1], 2));
            double d2 = sqrt(pow(v2[0], 2) + pow(v2[1], 2));
            return (d1 > d2);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // custom max_heap
        priority_queue<vector<int>, vector<vector<int>>, Compare> max_heap(points.begin(), points.end());

        vector<vector<int>> res;
        while (k--) {
            res.push_back(max_heap.top());
            max_heap.pop();
        }
        return res;
    }
};