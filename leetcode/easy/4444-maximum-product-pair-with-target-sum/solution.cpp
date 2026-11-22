class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // val -> index
        vector<int> ans = {-1, -1};
        int maxProd = INT_MIN;

        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];

            if (seen.count(complement)) {
                if (nums[i] != complement) {
                    int prod = nums[i] * complement;
                    if (prod > maxProd) {
                        maxProd = prod;
                        int j = seen[complement];
                        ans = (nums[i] > complement) ? vector<int>{i, j} : vector<int>{j, i};
                    }
                }
            }
            // Record latest index seen for this value
            seen[nums[i]] = i;
        }

        return ans;
    }
};