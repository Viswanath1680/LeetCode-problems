class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int sizeK;

public:
    KthLargest(int k, vector<int>& nums) {
        sizeK = k;
        for( auto n : nums )    add(n);
    }
    
    int add(int val) {
        minHeap.push(val);
        if( minHeap.size() > sizeK )    minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */