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
    ListNode* findMiddleOfList(ListNode* root) {
    ListNode* fast = root;
    ListNode* slow = root;
    ListNode* prev = nullptr;
    while (fast!=nullptr && fast->next !=nullptr) {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    if (prev!=nullptr)
        prev->next = nullptr;
    return slow;
}
ListNode* sortListWithStarts(ListNode* left, ListNode* right) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while (left!=nullptr && right!=nullptr) {
        if (left->val>right->val) {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }else {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
    }
    if (left!=nullptr)
        temp->next = left;
    if (right!=nullptr)
        temp->next = right;
    return dummy->next;
}
ListNode* sortList(ListNode* head) {
    if (head==nullptr || head->next==nullptr)return head;
    ListNode* middle = findMiddleOfList(head);
    head = sortList(head);
    middle = sortList(middle);
    return sortListWithStarts(head, middle);
}
};