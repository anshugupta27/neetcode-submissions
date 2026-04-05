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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2, *head = new ListNode(), *dummyPtr = head;
        int div = 0, sum = 0;
        while (ptr1 && ptr2) {
            sum = ptr1 -> val + ptr2 -> val + div;
            int rem = sum % 10;
            div = sum / 10;
            ListNode* newList = new ListNode (rem);
            dummyPtr -> next = newList;
            dummyPtr = dummyPtr -> next;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        while (ptr1) {
            sum = ptr1 -> val + div;
            int rem = sum % 10;
            div = sum / 10;
            ListNode* newList = new ListNode (rem);
            dummyPtr -> next = newList;
            dummyPtr = dummyPtr -> next;
            ptr1 = ptr1 -> next;
        }
        while (ptr2) {
            sum = ptr2 -> val + div;
            int rem = sum % 10;
            div = sum / 10;
            ListNode* newList = new ListNode (rem);
            dummyPtr -> next = newList;
            dummyPtr = dummyPtr -> next;
            ptr2 = ptr2 -> next;
        }
        if (div)
       {
         ListNode* newList = new ListNode (div);
        dummyPtr -> next = newList;
       }
        return head -> next;
    }
};