class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
 map<pair<int, int>, int>m;
    int i=0, j=1, ans = 0;
    int n= nums.size();
    while (j<nums.size()) {
        if (nums[i]==nums[j])ans++;
        else {
            m[{nums[i], nums[j]}]++;
            m[{nums[j], nums[i]}]++;
        }
        i++;
        j++;
    }
    int maxi=0;
    for (auto k: m) {
        maxi = max(maxi, k.second);
    }
    return ans+ maxi;
    }
};