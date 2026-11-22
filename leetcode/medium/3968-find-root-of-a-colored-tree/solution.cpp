class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
         int n = colors.size();
    vector<vector<int>> adj(n);
    // Make adjacency list
    for(vector<int> p: edges){
        int u = p[0];
        int v = p[1];
        char uC = colors[u];
        char vC = colors[v];
        if (uC=='R' && vC =='B') {
            adj[u].push_back(v);
        }
        else if (uC == 'B' && vC=='R') {
            adj[v].push_back(u);
        }
        else if (uC=='B' && vC=='W') {
            adj[u].push_back(v);
        }
        else if (uC=='W' && vC=='B') {
            adj[v].push_back(u);
        }
        else if (uC=='W' && vC=='R') {
            adj[u].push_back(v);
        }
        else if (uC=='R' && vC=='W') {
            adj[v].push_back(u);
        }else return -1;
    }
    // Check degrees
    int nodeWithDegreeZero = -1;
    vector<int> inDegrees(n, 0);
    for (int i=0; i<n; i++) {
        if (adj[i].size()>2)return -1;
        for (int j=0; j<adj[i].size(); j++) {
            inDegrees[adj[i][j]]++;
            if (inDegrees[adj[i][j]]>1)return -1;
        }
    }
    // Find node with inDegree of 0
    for (int i =0 ; i<n; i++)
        if (inDegrees[i]==0) {
            if (nodeWithDegreeZero!=-1)return -1;
            nodeWithDegreeZero = i;
        }
    if (nodeWithDegreeZero==-1)return -1;
    
    return nodeWithDegreeZero;
    }
};