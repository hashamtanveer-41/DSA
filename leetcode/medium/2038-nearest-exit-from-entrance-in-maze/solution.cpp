class Solution {
public:
bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       int n= maze.size();
    int m = maze[0].size();
    queue<pair<pair<int, int>, int>> q;
    q.push({{entrance[0], entrance[1]}, 0});
    maze[entrance[0]][entrance[1]] = '+';
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        int lvl = p.second;
        q.pop();
        int row = p.first.first;
        int col = p.first.second;
        maze[row][col] = '+';
        // Check is it the boundary
        if ((row!=entrance[0]||col!=entrance[1])&&(row==0||row==n-1 ||col==0 ||col==m-1))return lvl;
        // We havent reached the boundary so move in all 4 direction
        for (int i=0; i<4; i++) {
            int r = row + x[i];
            int c = col + y[i];
            // Check that r and c arent + and they arent entrance
            if (valid(r, c, n, m) && maze[r][c]!='+' && (r != entrance[0] || c!=entrance[1])) {
                // Valid movement
                q.push({{r ,c}, lvl+1});
                maze[r][c] = '+';
            }
        }
    }
    return -1;
    }
};