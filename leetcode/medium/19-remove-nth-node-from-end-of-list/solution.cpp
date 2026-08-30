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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head==nullptr)return nullptr;
    if (n==0)return head;
    int length = 0;
    ListNode* traverse = head;
    while (traverse!=nullptr) {
        length++;
        traverse= traverse->next;
    }
    int curr = length-n;
    if (curr==0)return head->next;
    length=0;
    traverse = head;
    while (traverse!=nullptr) {
        length++;
        if (length==curr) {
            traverse->next = traverse->next->next;
        }
        traverse = traverse->next;
    }
    return head;
}
};