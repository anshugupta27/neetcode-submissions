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
    void reorderListUtil (ListNode*& head, ListNode* tail) {
        if (!tail) return ;

        reorderListUtil (head, tail -> next);
        if (!head) return;

        if(head == tail || head -> next == tail) {
            head -> next = tail;
            tail -> next = NULL;
            head = NULL;
            return;
        }
        ListNode* headNext = head -> next;
        head -> next = tail;
        tail -> next = headNext;
        head = headNext;

    }
    void reorderList(ListNode* head) {
        reorderListUtil (head, head);
        
    }
};