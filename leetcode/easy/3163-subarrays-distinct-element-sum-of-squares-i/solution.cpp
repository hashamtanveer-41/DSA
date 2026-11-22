class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        // for n numbers i know that it will have n*(n+1)/2 subarrays 
        int res = 0;
        for(int i=0; i<n; i++){
             unordered_set<int> st;
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                res += st.size()* st.size();
            }
        }
        return res;
    }
};