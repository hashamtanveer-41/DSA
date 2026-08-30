class Solution {
public:
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    int left =0, right = 0;
    unordered_map<int, int> f;
    while (right<n) {
        if (!f.empty() && f.find(nums[right])!=f.end()) {
            return true;
        }
        int windowSize = right-left+1;
        if (windowSize==(k+1)) {
            f[nums[left]]--;
            if (f[nums[left]]==0)f.erase(nums[left]);
            left++;
        }
        f[nums[right]]++;
        if (f[nums[right]]==0)f.erase(nums[right]);
        right++;
    }
    return false;
}
};