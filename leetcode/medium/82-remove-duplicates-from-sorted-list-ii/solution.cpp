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
      if (head == nullptr)return nullptr;
    ListNode* read = head->next;
    ListNode* write = head;
    ListNode* trail = nullptr;
   while (read!=nullptr) {
        while (read!=nullptr && read->val==write->val) {
            read = read->next;
        }
       if (trail==nullptr && read!=head->next)// i have duplicates for head
            head = read;
       else {
           if (trail!=nullptr && read !=write->next) {
               // i am not at head
               trail->next = read;
           }else
               trail = write;
       }
        write = read;
    }
    return head;
    }
};