class Solution {
public:
   vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> less={};
    vector<int> greater={};
    vector<int> equal = {};
    for (int i = 0; i < n; i++) {
        if (nums[i]<pivot)less.push_back(nums[i]);
        else if (nums[i]==pivot)equal.push_back(nums[i]);
        else greater.push_back(nums[i]);
    }
    vector<int> res;
    for (int i: less)res.push_back(i);
    for (int i: equal)res.push_back(i);
    for (int i: greater)res.push_back(i);
    return  res;
}
};