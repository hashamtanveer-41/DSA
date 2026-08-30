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
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head!=nullptr) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head= next;
    }
    return prev;
    }
    int pairSum(ListNode* head) {
        int n =0, res =head->val;
    ListNode* current = head;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast!=nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head1 = reverseList(slow);
    while (head1!=nullptr) {
        int sum = head1->val + current->val;
        res = max(res, sum);
        current = current->next;
        head1 = head1->next;
    }
    return res;
    }
};