class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
    int res = 0;
    sort(nums.begin(), nums.end());
    int left = 0, right = n-1;
    while (left<right) {
        int sum = nums[left]+nums[right];
        if (sum==k) {
            res++;
            left++;right--;
        }else if (sum>k)right--;
        else left++;
    }
    return res;
    }
};