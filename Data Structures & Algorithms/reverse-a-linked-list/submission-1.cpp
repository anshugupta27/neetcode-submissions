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
    ListNode* reverseListRecursive (ListNode* head) {
        if (!head || !head -> next) return head;

        ListNode* latestHead = reverseListRecursive (head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return latestHead;



    }
    ListNode* reverseList(ListNode* head) {
        // iteratively -> take a prev variable , next and current , initially prev will point to null and then later in the end when curr points to nul lthen prev will point to the reviser head 
        // ListNode* prev = NULL, *curr = head;
        // while (curr) {
        //     ListNode* next = curr -> next;
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;

        // recursively
        // so always return the newHead after making the currenthead -> next -> pointing to head;
        return reverseListRecursive (head);
        
    }
};