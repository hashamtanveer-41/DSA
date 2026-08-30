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
    ListNode* oddEvenList(ListNode* head) {
        if (head==nullptr)return nullptr;
    ListNode*  evenHead = head->next;
    ListNode*  evenPtr = head->next;
    ListNode*  oddPtr = head;
    while (evenPtr != nullptr && evenPtr->next!=nullptr  && oddPtr !=nullptr && oddPtr->next!=nullptr) {
        oddPtr -> next = evenPtr->next;
        oddPtr = evenPtr->next;
        if(oddPtr)
       { evenPtr ->next = oddPtr->next;
        evenPtr = oddPtr->next;}
    }
    oddPtr->next = evenHead;
    return head;
    }
};