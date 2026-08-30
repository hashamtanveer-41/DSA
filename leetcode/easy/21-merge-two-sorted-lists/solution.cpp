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
    if (list1==nullptr)return list2;
    if (list2==nullptr)return list1;
    ListNode* left1 = list1;
    ListNode* left2 = list2;
    ListNode* newList;
    if (left1->val > left2->val) {
        newList = new ListNode(left2->val);
        left2 = left2->next;
    }else {
        newList =new ListNode(left1->val);
        left1 = left1->next;
    }
    ListNode* head = newList;
    while (left1!=nullptr&&left2!=nullptr) {
        if (left1->val > left2->val) {
            newList->next = new ListNode(left2->val);
            left2 = left2->next;
        }else {
            newList->next = new ListNode(left1->val);
            left1 = left1->next;
        }
        newList = newList ->next;
    }
    if (left1!=nullptr)newList->next = left1;
    if (left2!=nullptr)newList->next = left2;
    return head;
}
};