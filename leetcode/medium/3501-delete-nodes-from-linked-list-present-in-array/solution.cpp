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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_map<int, int> freq;
    ListNode* curr = head;
    ListNode* prevCurr = nullptr;
    for (int num:nums)freq[num]++;
    while (curr!=nullptr) {
        if (freq.find(curr->val)!=freq.end()) {
            if (curr==head) {
                head = head->next;
            }else {
                prevCurr->next = curr->next;
            }
        }else {
            prevCurr = curr;
        }
        curr = curr->next;
    }
    return head;
}
};