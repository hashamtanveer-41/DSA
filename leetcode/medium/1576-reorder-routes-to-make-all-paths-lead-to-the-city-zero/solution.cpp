class Solution {
public:
    void dfsVII(vector<vector<pair<int, bool>>>& adj, pair<int, bool> node,int parent, int& res) {
    if (node.second)res++;
    for (int i=0; i<adj[node.first].size(); i++) {
        if (adj[node.first][i].first!=parent)
            dfsVII(adj, adj[node.first][i], node.first, res);
    }
}
int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, bool>>> adj(n);
    for (int i=0; i<connections.size(); i++) {
        int src = connections[i][0];
        int dist = connections[i][1];
        adj[src].push_back({dist, true});
        adj[dist].push_back({src, false});
    }
    int res = 0;
    dfsVII(adj, {0, false}, 0, res);
    return res;
}
};  