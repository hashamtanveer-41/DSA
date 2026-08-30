class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
    int n = nums.size();
    int evenPtr = 0, oddPtr = 1;
    while (evenPtr<n&&oddPtr<n) {
        if (nums[evenPtr]%2==0) {
            evenPtr+=2;
        } else if (nums[oddPtr]%2==1) {
            oddPtr+=2;
        }else {
            swap(nums[evenPtr], nums[oddPtr]);
        }
    }
    return nums;
}
};