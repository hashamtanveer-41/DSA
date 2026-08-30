class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> f;
    vector<int> result;
    for (int i = 0; i < nums2.size(); i++)
        f[nums2[i]] = i;
    for (int j=0; j< nums1.size(); j++) {
        int idx = f[nums1[j]];
        int res = -1;
        for (int k=idx+1; k<nums2.size(); k++ ) {
            if (nums2[k]>nums1[j]) {
                res = nums2[k];
                break;
            }
        }
        result.push_back(res);
    }
    return result;
}
};