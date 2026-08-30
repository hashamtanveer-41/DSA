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
    struct Node2 {
    ListNode* node;
    Node2(ListNode* listNode) : node(listNode) {}
};
struct comp3 {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (n==0)return nullptr;
    priority_queue<ListNode*, vector<ListNode*>, comp3> pq;
    for (int i = 0; i < n; i++) {
        if (lists[i] != nullptr) {
            pq.push(lists[i]);
        }
    }
    ListNode* dummy = new ListNode(0);
    ListNode* dummyNext = dummy;
    while (!pq.empty()) {
        ListNode* n = pq.top();
        pq.pop();
        int v = n->val;
        dummyNext->next = n;
        dummyNext = dummyNext->next;
        if (n->next!=nullptr) {
            pq.push({n->next});
        }
    }
    return dummy->next;
}
};