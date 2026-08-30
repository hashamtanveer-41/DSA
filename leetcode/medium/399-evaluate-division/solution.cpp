class Solution {
public:
    double dfsVIII(unordered_map<string, unordered_map<string,  double>>& adj, string& start, string& target, unordered_map<string, int>& vis) {
    if (start==target)return 1;
    // In starts map you have to go to every child and check if they have target
    if (adj.find(start)==adj.end())return -1;
    unordered_map<string, double> temp = adj[start];
    if (temp.size()==0)return -1;
    if (temp.find(target)!=temp.end())return temp[target];
    vis[start]++;
    for (auto& p: temp) {
        string newStart = p.first;
        if (vis.find(p.first)==vis.end()) {
            double ans = dfsVIII(adj, newStart, target, vis);
            if (ans!=-1)return ans*p.second;
        }
    }
    return -1;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string,  double>> adj;
    for (int i=0; i<equations.size(); i++) {
        string src = equations[i][0] ;
        string dest = equations[i][1];
        double val = values[i];
        adj[src][dest] = val ;
        adj[dest][src] = 1/val;
    }
    vector<double> res(queries.size(), -1);
    for (int i = 0; i<queries.size(); i++) {
        vector<string> query = queries[i];
        if (adj.find(query[0])!=adj.end()) {
            unordered_map<string, int> vis;
            // It means the start exists and there is possibility that we might get an answer
            res[i] = dfsVIII(adj, query[0], query[1], vis);
        }
    }
    return res;
}
};