class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
    int m = nums2.size();
    int left = 0, right = 0;
    vector<int>final;
    while (left<n && right<m) {
        if (nums1[left]<nums2[right]) {
            final.push_back(nums1[left]);
            left++;
        }else {
            final.push_back(nums2[right]);
            right++;
        }
    }
    while (left<n){
        final.push_back(nums1[left]);left++;}
    while (right<m){
        final.push_back(nums2[right]);right++;}
    int o = (n+m-1)/2;
    if ((n+m)%2==0) {
        return (static_cast<double>(final[o])+final[o+1])/2;
    }else {
        return final[o];
    }
    }
};