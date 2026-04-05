class MedianFinder {
public:
    // create 2 heaps
    // max heap and min heap
    // store all the small values in max Heap and larger values in min heap 
    // always push in max heap -> then take top of max and push in min heap -> then check size of minheap if cgreater than max heap then pop from min and push in pop
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        if ((maxHeap.size() + minHeap.size()) % 2) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */