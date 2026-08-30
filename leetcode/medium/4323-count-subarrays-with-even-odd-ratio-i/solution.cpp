class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
       int n = nums.size(), res =0;
    int even = 0, odd =0;
    for (int i=0; i<n; i++) {
        even =0; odd=0;
        for (int j= i; j<n;j++) {
            if (nums[j]%2==0)even++;
            else odd++;
            if (b*even <=a*odd)res++;
        }
    }
    return res;
    }
};