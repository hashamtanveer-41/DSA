class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
    for (int i=0; i<prerequisites.size(); i++) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    vector<int> inDegrees(numCourses, 0);
    for (int i=0; i<numCourses;i++) {
        for (int val: adj[i])
            inDegrees[val]++;
    }
    queue<int> q;
    vector<int> res;
    for (int i=0; i<inDegrees.size(); i++)
        if (inDegrees[i]==0)q.push(i);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int val: adj[curr]) {
            inDegrees[val]--;
            if (inDegrees[val]==0)
                q.push(val);
        }
    }
    if (res.size()<numCourses)return {};
    return res;
    }
};