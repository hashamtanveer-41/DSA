class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51, 0);
    int left = 0, right =0; 
    int n = nums.size();
        if (k==n)return *max_element(nums.begin(), nums.end());

    while (right< n) {
        int windLen = right -left +1;
        if (windLen == k) {
            for (int i=left; i<=right; i++) {
                freq[nums[i]]++;
            }
            left++;
        }
        right++;
    }
    sort(nums.begin(), nums.end());
    for (int i=n-1; i>=0; i--)
                if (freq[nums[i]]==1)return nums[i];

    return -1;
    }
};