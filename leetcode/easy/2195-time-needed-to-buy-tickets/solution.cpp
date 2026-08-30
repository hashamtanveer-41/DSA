class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n =tickets.size();
    int target = tickets[k], res = 0;
    for (int i=0;  i<n; i++) {
        if (i<=k) {
            res +=min(target, tickets[i]);
        }else {
            res +=min(target-1, tickets[i]);
        }
    }
    return res;
    }
};