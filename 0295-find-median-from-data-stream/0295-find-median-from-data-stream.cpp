// Maintain two heaps, left one is for left half -> max heap
// the other one is for right half -> min Heap. So that, the tops represent mid values in the stream

// size(left) >= size(right)
class MedianFinder {
private:
    priority_queue<int> maxHeap; // left heap
    priority_queue<int, vector<int>, greater<int>>  minHeap;
public:
    MedianFinder() {
        // empty
    }

//First, push into max-heap (left), Since it's the heap of smaller elements
// Then push top of max-heap into min-heap (to maintain balance)
// If min-heap has more elements → move its top back to max-heap
    void addNum(int num) {
        maxHeap.push( num );
        auto top = maxHeap.top(); maxHeap.pop();   
        minHeap.push(top);
        if( minHeap.size() > maxHeap.size() ){
            maxHeap.push( minHeap.top() );
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if( maxHeap.size() == minHeap.size() )
            return ( maxHeap.top() + minHeap.top() ) / 2.0;
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */