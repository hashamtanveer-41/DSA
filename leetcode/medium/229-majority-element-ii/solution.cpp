class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    vector<int> res;
    int n = nums.size();
    int majorElementCondition = floor(n/3);
    for (int i=0; i<nums.size(); i++)
        freq[nums[i]]++;
    for (auto var: freq) {
        if (var.second > majorElementCondition)
            res.push_back(var.first);
    }
    return res;
}
};