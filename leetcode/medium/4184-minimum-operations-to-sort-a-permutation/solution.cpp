class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();
    int forward_counter = 0;
    for(int i=0; i<=n-2; i++){
        if(nums[i]>nums[i+1])forward_counter++;
    }
    if(nums[n-1]>nums[0])forward_counter++;
    int backward_counter = 0;
    for(int i=0; i<n-1;i++){
        if(nums[i]<nums[i+1])backward_counter++;
    }
    if(nums[n-1]<nums[0])backward_counter++;
    if(backward_counter>1 && forward_counter>1)return -1;
        int zero_idx = 0;
        while (zero_idx < n) {
            if (nums[zero_idx] == 0) break;
            zero_idx++;
        } int ans = 1e9;
        if (forward_counter <= 1) {
            // Choice 1: Simply rotate left until 0 lands at index 0
            ans = min(ans, zero_idx);
            // Choice 2: Rotate left until 0 lands at the back, reverse, then rotate again
            ans = min(ans, n - zero_idx + 2);
        }
        
        // Case B: Array is in a reverse sorted cycle
        if (backward_counter <= 1) {
            // Choice 3: Rotate first to align the largest element, then reverse
            ans = min(ans, n - zero_idx);
            // Choice 4: Reverse first, then rotate left until 0 reaches the front
            ans = min(ans, zero_idx + 2);
        }

        return ans;
}

};