class Solution {
public:
   vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;
    int n = nums1.size();
    int k = nums2.size();
    for (int i=0; i<n; i++)
        freq1[nums1[i]]++;
    for (int i=0; i<k; i++)
        freq2[nums2[i]]++;
    int res1=0;
    for (auto var: freq1) {
        if (freq2.count(var.first)) {
            res1 += var.second;
        }
    }
    int res2=0;
    for (auto var: freq2) {
        if (freq1.count(var.first)) {
            res2 += var.second;
        }
    }
    return {res1, res2};
}
};