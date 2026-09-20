class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sumGas = accumulate(gas.begin(), gas.end(), 0);
    int sumCost = accumulate(cost.begin(), cost.end(), 0);
    if (sumGas<sumCost)
        return -1;
    int n = gas.size();
    int tank = 0;
    int res = 0;
    for (int i=0; i<n;i++) {
        tank += gas[i] - cost[i];
        if (tank<0) {
            res = i+1;
            tank = 0;
        }
    }
    return res;
}
};