/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, int> freq;
    ListNode* slow = headA;
    while (slow!=nullptr) {
        freq[slow]++;
        slow = slow->next;
    }
    ListNode* fast = headB;
    while (fast!=nullptr) {
        if (freq.find(fast)!=freq.end()) return fast;
        fast=fast->next;
    }
    return nullptr;
}
};