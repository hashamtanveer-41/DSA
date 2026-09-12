class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int num: nums)st.insert(num);
        for(int i=1; i<=n; i++){
            if(st.count(i)==0)return i;
        }
        return n+1;
    }
};