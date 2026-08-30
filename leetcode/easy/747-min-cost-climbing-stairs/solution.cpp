class Solution {
public:
  
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int next = 0, next_next = 0;
    for (int i = n-1; i>=0; i--) {
        int sum = cost[i] + min(next, next_next);
        next_next = next;
        next = sum;
    }
    return min(next_next, next);
}
};