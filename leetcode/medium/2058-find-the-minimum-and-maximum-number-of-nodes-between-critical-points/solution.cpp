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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head==nullptr && head->next==nullptr)return {-1, -1};
    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* next = head->next->next;
    vector<int> criticalPoints;
    int idx = 2;
    while (next!=nullptr){
        // Maxima
        if (curr->val>prev->val && curr->val>next->val ) {
            criticalPoints.push_back(idx);
        }else
        // Minima
        if (curr->val < prev->val && curr->val < next->val) {
            criticalPoints.push_back(idx);
        }
        // Neither max nor min
        idx++;
        prev = curr;
        curr = next;
        next = next->next;
    }
     if (criticalPoints.size()<=1)return {-1, -1};
    int minVal = criticalPoints[1] - criticalPoints[0];
    int maxVal = criticalPoints[criticalPoints.size()-1] - criticalPoints[0];
    for (int i=2; i<criticalPoints.size(); i++) {
        int diff =criticalPoints[i]-criticalPoints[i-1];
        minVal = min(diff, minVal);
    }
    // I have my critical points ready
    return {minVal, maxVal};
    }
};