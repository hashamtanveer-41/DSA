class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
         int n = nums.size();
    vector<int> left;
    vector<int> right;
    left.push_back(nums[0]);
    right.push_back(nums[1]);
    for (int i=2; i<n; i++) {
        if (left.back()>right.back())
            left.push_back(nums[i]);
        else
            right.push_back(nums[i]);
    }
    for (int val: right)
        left.push_back(val);
    return left;
    }
};