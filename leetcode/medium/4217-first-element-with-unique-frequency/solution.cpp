class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int>freq;
    int n = nums.size();
    for (int num : nums)freq[num]++;
    unordered_map<int, int>freqIdx;
    for (int i = 0; i< n; i++) {
        if (freqIdx.find(freq[nums[i]])==freq.end()) {
            // Not found
            freqIdx[freq[nums[i]]] = i;
        }else {
            // Found
            if (freqIdx[freq[nums[i]]] !=-1 && nums[freqIdx[freq[nums[i]]]]!=nums[i])
                freqIdx[freq[nums[i]]] = -1;
        }
    }
    int idx = INT_MAX;
    for (auto& p: freqIdx) {
        if (p.second!=-1)
            idx = min(idx, p.second);
    }
    if (idx== INT_MAX)return -1;
    return nums[idx];
    }
};