class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = *min_element(nums1.begin(), nums1.end());
    bool even = false;
    if (minVal%2==0)even = true;
    int n = nums1.size();
    for (int i =0; i< n; i++) {
        if (even) {
            if (nums1[i]%2!=0 )
                if ( (nums1[i]-minVal)<1 || (nums1[i]-minVal)%2!=0)
                    return false;
        }else {
            if (nums1[i]%2==0)
                if ( (nums1[i]-minVal)<1 || (nums1[i]-minVal)%2==0)
                    return false;
        }
    }
    return true;
    }
};