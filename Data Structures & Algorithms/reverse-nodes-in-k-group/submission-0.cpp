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
    ListNode* reverseKGroupUtil (ListNode* head, int k) {
        if (!head) return NULL;
        int nodesToReverse = k;
        ListNode* prev = NULL, *curr = head, *next, *tempCurr = head;
        while (tempCurr && nodesToReverse) {
            tempCurr = tempCurr -> next;
            nodesToReverse--;
        }
        if (nodesToReverse) return head;
        nodesToReverse = k;
        while (curr && nodesToReverse) {
            next = curr -> next;
            curr -> next = prev ;
            prev = curr;
            curr = next; 
            nodesToReverse--;
        }
        ListNode* nextLoop = reverseKGroupUtil (curr, k);
        head -> next = nextLoop ;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseKGroupUtil (head, k);
    }
};