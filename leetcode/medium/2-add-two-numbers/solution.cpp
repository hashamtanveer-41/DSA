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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* curr1 = l1;
    ListNode* curr2 = l2;
    bool start = true;
    ListNode* newList;
    ListNode* newListPtr;
    int carry = 0, val=0;
    while (curr1!=nullptr && curr2!=nullptr) {
        int sum = curr1->val+curr2->val+carry;
        carry =0;
        if (sum>9) {
            carry = sum/10;
            val = sum%10;
        }else val = sum;
        if (start) {
            newList = new ListNode(val);
            newListPtr = newList;
            start = false;
        }else {
            newListPtr->next = new ListNode(val);
            newListPtr = newListPtr->next;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while (curr1!=nullptr) {
        int sum = curr1->val+carry;
        carry = 0;
        if (sum>9) {
            carry = sum/10;
            val = sum%10;
        }else val = sum;
        newListPtr ->next = new ListNode(val);
        newListPtr = newListPtr->next;
        curr1 = curr1->next;
    }
    while (curr2!=nullptr) {
        int sum = curr2->val+carry;
        carry = 0;
        if (sum>9) {
            carry = sum/10;
            val = sum%10;
        }else val = sum;
        newListPtr ->next = new ListNode(val);
        newListPtr = newListPtr->next;
        curr2 = curr2->next;
    }
    if (carry>0)newListPtr ->next = new ListNode(carry);
    return newList;

}
};