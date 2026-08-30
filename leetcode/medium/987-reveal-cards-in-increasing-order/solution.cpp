class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
    queue<int>index;
    for (int i=0; i<deck.size(); i++) {
        index.push(i);
    }
    vector<int>res;
    while (!index.empty()) {
        int curr = index.front();
        index.pop();
        res.push_back(curr);
        if (!index.empty()) {
            int next = index.front();
            index.pop();
            index.push(next);
        }
    }
    vector<int>result(deck.size());
    for (int i =0; i<res.size(); i++) {
        result[res[i]] = deck[i];
    }
    return result;
    }
};