
struct DoubleListNode {
    int data;
    DoubleListNode* next;
    DoubleListNode* prev;
    DoubleListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};
            class LRUCache {
        public:
        unordered_map<int, pair<int, DoubleListNode*> > mp;
        DoubleListNode* head = nullptr;
        DoubleListNode* end = nullptr;
        int val = 0;
        LRUCache(int capacity) {
            val = capacity;
        }

        int get(int key) {
          // Here we know which node is being asked for
            if (mp.find(key)==mp.end())return -1;
            // the key exists
            DoubleListNode* node = mp[key].second;
            if (node!=end) {
                // this node should go to end
                // make its prev nodes next assigned to its next node
                if (node->prev!=nullptr)
                    node->prev->next = node->next;
                if (head==node)
                    head = head->next;
                // make its next node prev assigned to prev node
                if (node->next!=nullptr)
                    node->next->prev = node->prev;
                // now this node is out of list just make the end node next to this node
                end->next = node;
                // and this nodes prev to end node and move end node to this node
                node->prev = end;
                end = node;
                // and make this nodes next to nullptr
                node->next = nullptr;
                // finally return the value of this key
            }
            return mp[key].first;
        }

        void put(int key, int value) {
            if (mp.find(key)!=mp.end()) {
                // it means the key exists already you just have to update the value and move it to the end
                DoubleListNode* temp = mp[key].second;
                if (temp!=end) {
                    if (temp->next!=nullptr)
                        temp->next->prev = temp->prev;
                    if (head==temp)
                        head = head->next;
                    if (temp->prev!=nullptr)
                        temp->prev->next = temp->next;
                    end->next =temp;
                    temp->prev = end;
                    end = temp;
                    temp->next = nullptr;
                }
                mp[key] = {value, temp};
            }
            else if (mp.size()<val) {
                // start is the pointer where i will put my values
                if (head==nullptr) {
                    head = new DoubleListNode(key);
                    end = head;
                }else {
                    DoubleListNode* temp = end;
                    end->next = new DoubleListNode(key);
                    end = end->next;
                    end->prev = temp;
                }
                    mp[key] = {value, end};
            }else {
                // The capacity is reached now i have to replace
                // my head points to the start of the list or the least used one node
                // i have to remove that node from the list and from the map
                // to remove from the map just erase it and to remove from the list just
                // place the value of old key one to new key and push this new key with same node
                // value in the map
                mp.erase(head->data);
                head->data = key;
                mp[key] = {value, head};
                DoubleListNode* temp = head;
                if (head != end) {
                    head = head->next;
                    head->prev = nullptr;
                    // move the temp to last
                    end->next = temp;
                    temp->prev = end;
                    temp->next = nullptr;
                    end = temp;
                }
            }
        }
    };


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */