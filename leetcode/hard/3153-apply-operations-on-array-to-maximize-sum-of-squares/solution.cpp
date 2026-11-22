class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
      vector<int> freq(31, 0);
    for (int num: nums) {
        for (int i=0; i<31; i++) {
            bool is = num & (1 << i);
            if (is)freq[i]++;
        }
    }
    vector<int> res(k, 0);
    for (int i=0; i<31; i++) {
        int minOperations = min(freq[i], k);
        for (int j=0; j<minOperations; j++) {
            res[j] = res[j] | (1<<i);
        }
    }
    long long result = 0;
    int MOD = 1e9 + 7;
    for (int i=0; i<k; i++) {
        long long val = res[i];
        result = (result + (val*val)%MOD)%MOD;
    }
    return result;
    }
};