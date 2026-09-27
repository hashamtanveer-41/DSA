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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
    ListNode* lessPtr = less;
    ListNode* more = new ListNode(0);
    ListNode* morePtr = more;
    ListNode* curr = head;
    while (curr!=nullptr) {
        if (curr->val<x) {
            lessPtr->next = curr;
            lessPtr = lessPtr->next;
        }else {
            morePtr->next = curr;
            morePtr = morePtr->next;
        }
        curr = curr->next;
    }
    lessPtr->next = more->next;
    morePtr->next = nullptr;
    return less->next;
    }
};