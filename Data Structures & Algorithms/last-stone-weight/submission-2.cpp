class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i = 0 ; i < stones.size() ; i++) {
            maxHeap.push(stones[i]);
        }
        while (maxHeap.size() > 1) {
            int top = maxHeap.top();
            maxHeap.pop();
            int secondTop = maxHeap.top();
            maxHeap.pop();
            if (top != secondTop) {
                maxHeap.push(top-secondTop);
            }
        }
        return maxHeap.size() ? maxHeap.top() : 0;
    }
};