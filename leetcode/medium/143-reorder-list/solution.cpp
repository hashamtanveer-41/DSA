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
    void reorderList(ListNode* head) {
    if (head==nullptr)return;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast!=nullptr&&fast->next!=nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = reverseList(slow);
    ListNode* dummy = new ListNode(0);
    ListNode* dummyNext = dummy;
    while (head->next!=nullptr || fast->next!=nullptr) {
        if (head->next!=nullptr) {
           dummyNext->next = head;
            head = head->next;
            dummyNext = dummyNext->next;
        }
        if (fast->next!=nullptr) {
            dummyNext->next = fast;
            fast = fast->next;
            dummyNext = dummyNext->next;
        }
    }
    head= dummy->next;
}
};