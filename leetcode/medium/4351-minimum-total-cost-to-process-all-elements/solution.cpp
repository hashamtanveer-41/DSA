class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
    int MOD = 1e9 + 7;
    long long val = 0;
    long long resources = k;
    for (int i =0; i<n; i++) {
        if (resources<nums[i]) {
            int valN = ((nums[i] - resources) / k )+ 1;
            if ((nums[i]-resources)%k==0)valN--;
            resources = resources + valN * k;
            val += valN;
        }
        resources -= nums[i];
    }
    if (val%2==0) {
        long long divResult = val/2;
        long long part1 = divResult % MOD;
        long long part2 = (val+1) % MOD;
        return (part1 * part2)%MOD;
    }else {
        long long divResult = (val+1)/2;
        long long part1 = divResult % MOD;
        long long part2 = (val) % MOD;
        return (part1 * part2)%MOD;
    }
    }
};