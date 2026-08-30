class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> a(n);
    for (int i=0; i< times.size(); i++) {
        int s= times[i][0];
        int d= times[i][1];
        int w= times[i][2];
        a[s-1].push_back({d-1, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>dis(n, INT_MAX);
    pq.push({0, k-1});
    dis[k-1] = 0;
    while (!pq.empty()) {
        pair<int, int > p = pq.top();
        pq.pop();
        int node = p.second;
        int dist = p.first;
        if (dist>dis[node])continue;
        for (int j=0; j< a[node].size(); j++) {
            int neigh = a[node][j].first;
            int wt = a[node][j].second;
            if (dist+wt<dis[neigh]) {
                pq.push({dist+wt, neigh});
                dis[neigh] = dist +wt;
            }
        }
    }
    int maxElement = *max_element(dis.begin(), dis.end());
    if (maxElement==INT_MAX)return -1;
    return maxElement;
    }
};