class Solution {
public:
    int calcMaxDig(int num) {
    priority_queue<int>pq;
    while (num>0) {
        int val = num%10;
        pq.push(val);
        num = num/10;
    }
    int res = 0;
    while (!pq.empty()) {
        res = res * 10 + pq.top();
        pq.pop();
    }
    return res;
}
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
    long long res = 0;
    priority_queue<pair<int, pair<int,int>>> pq;
    for (int i=0; i<n; i++) {
        int val = calcMaxDig(nums[i]);
        if (val==nums[i])continue;
        pq.push({val-nums[i],{val, i}});
    }
    while (k-- && !pq.empty()) {
        pair<int, int> p = pq.top().second;
        pq.pop();
        res+=p.first;
        nums[p.second] = -1;
    }
    for (int num: nums) {
        if (num==-1)continue;
        res+=num;
    }
    return res;
    }
};