class Solution {
public:
        long long weightedSum(vector<int>& parent, vector<int>& nums) {
            int n = parent.size();
    vector<vector<int>> a(n);
    for (int i =0; i< n; i++) {
        if (parent[i]!=-1)
            a[parent[i]].push_back(i);
    }
    queue<pair<int, int>> q;
    q.push({0, 1});
    long long res = 0;
    int h = INT_MIN;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int depth = p.second;
        h = max(depth, h);
        for (int j =0; j<a[node].size(); j++) {
            q.push({a[node][j], depth+1});
        }
    }
    q.push({0, 1});
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int depth = p.second;
        res += (long long) nums[node] * (long long) (h - depth + 1);
        for (int j =0; j<a[node].size(); j++) {
            q.push({a[node][j], depth+1});
        }
    }
    return res;
        }
};