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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head -> next) return NULL;
        ListNode* fastPtr = head, *slowPtr = head;
        int nFromBegg = n;
        while (fastPtr && nFromBegg > 0) {
            fastPtr = fastPtr -> next;
            nFromBegg--;
        }
        while (fastPtr && fastPtr -> next) {
            fastPtr = fastPtr -> next;
            slowPtr = slowPtr -> next;
        }
        if (!fastPtr) return head -> next;
        if (slowPtr && slowPtr -> next) slowPtr -> next = slowPtr -> next -> next;
        return head;
    }
};