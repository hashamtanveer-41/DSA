class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;
    for (int i=0; i<nums1.size(); i++)
        freq1[nums1[i]]++;
    for (int i=0; i<nums2.size(); i++)
        freq2[nums2[i]]++;
    vector<int> res1;
    vector<int> res2;
    auto it = freq1.begin();
    while (it != freq1.end()) {
        auto key = it->first;
        if (freq2.find(key) == freq2.end()) {
            res1.push_back(key);
            it = freq1.erase(it);
        } else {
            ++it;
        }
    }
     it = freq2.begin();
    while (it != freq2.end()) {
        auto key = it->first;
        if (freq1.find(key) == freq1.end()) {
            res2.push_back(key);
            it = freq2.erase(it); 
        } else {
            ++it;
        }
    }

    return {res1, res2};
}
};