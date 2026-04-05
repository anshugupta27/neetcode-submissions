/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Comp {
        bool operator() (ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> minHeap;
        ListNode* dummyHead = new ListNode(), *dummyHeadPtr = dummyHead;

        for (auto it : lists) {
            if (it) minHeap.push (it);
        }
        while (minHeap.size()) {
            ListNode* top = minHeap.top();
            minHeap.pop();
            if (!top) continue;
            
            dummyHeadPtr -> next = top;
            dummyHeadPtr = dummyHeadPtr -> next;
            ListNode* topNext = top -> next;
            dummyHeadPtr -> next = NULL;
            if (topNext) minHeap.push (topNext);
            
        }
        return dummyHead -> next;

    }
};