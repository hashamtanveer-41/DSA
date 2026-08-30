class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> freq(maxVal+1, 0);
    vector<int> res;
    for (int num:nums) {
        freq[num] = 1;
    }
    for (int i=minVal+1; i<maxVal; i++) {
        if(freq[i] == 0)res.push_back(i);
    }
    return res;
    }
};