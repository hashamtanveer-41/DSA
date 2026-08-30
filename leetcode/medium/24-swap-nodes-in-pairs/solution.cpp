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
    void reverse(ListNode* head, int times){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(times--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return;
    }
    ListNode* swapPairs(ListNode* head) {
        int size = 2;
        if(head == nullptr)return head;
        ListNode* left = head;
        ListNode* res = nullptr;
        ListNode* prevLeft =nullptr;
        ListNode* right;
        while(true){
            right = left;
            for(int i =0; i< size-1; i++){
                if(right==nullptr)break;
                right = right->next;
            }
            if(right){
                ListNode* nextLeft = right->next;
                reverse(left, 2);
                if(prevLeft)prevLeft->next = right;
                prevLeft=left;
                if(res == nullptr)res =right;
                left = nextLeft; 
            }else{
                if(prevLeft)prevLeft->next = left;
                if(res==nullptr)res=left;
                break;
            }
        }
            return res;
    }
};