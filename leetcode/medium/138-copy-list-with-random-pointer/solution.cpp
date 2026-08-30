/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
            if (head == nullptr) return nullptr;

    Node* newList = new Node(head->val);
    Node* current = head->next;
    Node* newCurr = newList;
     unordered_map<Node*, Node*> f;
    f[head] = newCurr;
    while (current!=nullptr) {
        Node* newNode = new Node(current->val);
        newCurr->next = newNode;
        f[current] = newNode;
        newCurr = newNode;
        current = current->next;
    }
    newCurr= newList;
    current = head;
    while (current!=nullptr) {
        if (current->random!=nullptr) {
            newCurr->random = f[current->random];
        }
        current = current->next;
        newCurr = newCurr->next;
    }
     return newList;
}
};