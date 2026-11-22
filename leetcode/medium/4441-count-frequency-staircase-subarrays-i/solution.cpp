class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
    int res = 0;
    res += n;
    for(int i=0; i<n; i++){
        map<int, pair<int, int>> mp;
        mp.insert({nums[i], {1,1}});
        for(int j=i+1; j<n; j++){
            if (mp.count(nums[j])>0) {
                mp[nums[j]].second+=1;
            }else {
                mp.insert({nums[j],{mp.size()+1,1}});
            }
            bool is = true;
            for (auto& p: mp) {
                if (p.second.second!=p.second.first){is=false;break;}
            }
            if (is)res++;
        }
    }
    return res;
    }
};