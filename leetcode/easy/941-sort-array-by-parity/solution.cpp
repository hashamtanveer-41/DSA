class Solution {
public:
   vector<int> sortArrayByParity(vector<int>& nums) {
    int n = nums.size();
    int data =0, traversal =1;
    while (traversal<n) {
        if (nums[data]%2==0) {
            data++;
        }else if (nums[traversal]%2==0) {
            swap(nums[traversal], nums[data]);
            data++;
        }
        traversal++;
    }
    return nums;
}
};