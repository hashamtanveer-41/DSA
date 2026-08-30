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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        unordered_map<int, int> freq;
        ListNode* curr = head;
        ListNode* prevCurr = nullptr;
        while (curr != nullptr) {
            freq[curr->val]++;
            if (freq.find(curr->val) != freq.end()) {
                if (freq[curr->val] > 1) {
                    freq[curr->val]--;
                    prevCurr->next = curr->next;
                    // prevCurr = curr->next;
                    curr = curr->next;
                    continue;
                }
            }
            prevCurr = curr;
            curr = curr->next;
        }
        return head;
    }
};