class Solution {
public:
    void findCombinationSumIII(vector<vector<int>>& res, int k, int n, int currSum, int i, vector<int>& temp) {
    if (currSum>n)return;
    if (k==0) {
        if (currSum == n)
            res.push_back(temp);
        return;
    }
    if (i>9)return;
    // Take
    temp.push_back(i);
    findCombinationSumIII(res, k-1, n, currSum+i,i+1, temp);
    temp.pop_back();
    // Leave
    findCombinationSumIII(res, k, n, currSum,i+1, temp);
}vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> temp;
    findCombinationSumIII(res, k, n, 0, 1, temp);
    return res;
}
};