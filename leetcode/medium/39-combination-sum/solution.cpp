class Solution {
public:
    void func2(vector<int>& arr, int n, int idx, vector<int>& diary, vector<vector<int>>& res, int sum, int target) {
    if (idx == n) {
        if (sum == target)
            res.push_back(diary);
        return;
    }
    func2(arr, n, idx+1, diary, res, sum, target);
    if (arr[idx]+sum<=target) {
        diary.push_back(arr[idx]);
        sum += arr[idx];
        func2(arr, n, idx, diary, res, sum, target);
        diary.pop_back();
        sum -= arr[idx];
    }
    return;
}
vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> res;
    vector<int> diary;
    int idx = 0;
    int sum = 0;
    func2(arr, n, idx, diary, res, sum, target);
    return res;
}
};