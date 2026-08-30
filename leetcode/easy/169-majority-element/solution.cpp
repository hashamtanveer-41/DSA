class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    int majorElementCondition = floor(n/2);
    for (int i=0; i<nums.size(); i++)
        freq[nums[i]]++;
    for (auto var: freq) {
        if (var.second > majorElementCondition)
            return var.first;
    }
    return -1;
}
};