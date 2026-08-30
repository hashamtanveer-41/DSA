class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<vector<int>> arr(3);
    int n = nums.size();
    for (int i =0; i< n; i++) {
        arr[nums[i]].push_back(i);
    }
    int res = INT_MAX;
    if (arr[2].size()==0 ||arr[1].size()==0)return -1;
    for (int i =0; i< arr[1].size(); i++) {
        for (int j=0; j< arr[2].size(); j++) {
            res = min(abs(arr[1][i] - arr[2][j]), res) ;
        }
    }
    return res;
    }
};