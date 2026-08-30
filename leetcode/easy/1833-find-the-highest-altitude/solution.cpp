class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> ans(n+1);
        ans.push_back(0);
        int max = INT_MIN;
        
        for(int i=1; i<=n; i++){
            ans[i]=gain[i-1]+ans[i-1];
            if(max<ans[i])max = ans[i];
        }
        if(max<0)return 0;
        return max;
    }
};