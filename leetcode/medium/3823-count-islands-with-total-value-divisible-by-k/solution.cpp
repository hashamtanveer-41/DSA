class Solution {
public:

bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}int res =0;
   long long count(vector<vector<int>>& grid, int k, int n, int m, int i, int j){
    if(!valid(i, j, n, m) || grid[i][j]==0)
        return 0;
    long long sum = grid[i][j];
    grid[i][j] = 0;
    long long left = count(grid, k, n, m, i, j-1);
    long long right = count(grid, k, n, m, i, j+1);
    long long top = count(grid, k, n, m, i-1, j);
    long long bottom = count(grid, k, n, m, i+1, j);
    return sum + top + bottom + left + right ;
}
int countIslands(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==0)continue;
            long long val = count(grid, k, n, m, i, j);
            if(val%k==0){
                res++;
            }
        }
    }
    return res;
}
    
};