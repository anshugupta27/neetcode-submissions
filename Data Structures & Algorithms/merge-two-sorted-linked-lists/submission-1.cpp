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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode ();
        ListNode *list1Ptr = list1, *list2Ptr = list2, *dummyHeadPtr = dummyHead;
        
        while (list1Ptr && list2Ptr) {
            if (list1Ptr -> val <=list2Ptr -> val) {
                dummyHeadPtr -> next = list1Ptr;
                dummyHeadPtr = dummyHeadPtr -> next;
                list1Ptr = list1Ptr -> next;
                dummyHeadPtr -> next = NULL;
            } else {
                dummyHeadPtr -> next = list2Ptr;
                dummyHeadPtr = dummyHeadPtr -> next;
                list2Ptr = list2Ptr -> next;
                dummyHeadPtr -> next = NULL;
            }
        }
        if (list1Ptr) {
            dummyHeadPtr -> next = list1Ptr;
        } else dummyHeadPtr -> next = list2Ptr;
        return dummyHead -> next;
        
    }
};