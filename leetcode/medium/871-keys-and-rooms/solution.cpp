class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
    vector<bool>vis(n, false);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int roomNo = q.front();
         q.pop();
        if (vis[roomNo])continue;
        vis[roomNo] = true;
       for(int num: rooms[roomNo])q.push(num);
    }
    for (bool is: vis)
        if (!is)return false;
    return true;
    }
};