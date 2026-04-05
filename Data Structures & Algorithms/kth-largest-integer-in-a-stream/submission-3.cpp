class KthLargest {
public:
    // implement minHeap and store the greatest number ie. the top of the heap should be greater than the incoming number
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxSize;
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for (int i = 0 ; i < nums.size() ; i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < maxSize) {
            minHeap.push(val);
        } else if (minHeap.size() == maxSize && minHeap.top() < val) {
            minHeap.pop();
            minHeap.push(val);
            
        } 
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */