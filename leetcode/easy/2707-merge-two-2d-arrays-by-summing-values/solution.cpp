class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int>> res;
    int left =0, right = 0;
    int n = nums1.size();
    int m = nums2.size();
    while (left<n && right<m) {
        vector<int> temp = nums1[left];
        vector<int> temp2 = nums2[right];
        if (temp[0]==temp2[0]) {
            int sum = temp[1]+temp2[1];
            res.push_back({temp[0], sum});
            left++;
            right++;
        }else if (temp[0]<temp2[0]) {
            res.push_back(temp);
            left++;
        }else {
            res.push_back(temp2);
            right++;
        }
    }
    if (left<n) {
        while (left<n) {
            res.push_back(nums1[left]);
            left++;
        }
    }
    if (right<m) {
        while (right<m) {
            res.push_back(nums2[right]);
            right++;
        }
    }

    return res;
}
};