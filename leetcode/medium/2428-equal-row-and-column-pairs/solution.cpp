class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       int n = grid.size();
    int res = 0;
    map< vector<int> , int > rows;
    for (int i=0; i<n; i++) {
        rows[grid[i]]++;
    }
    // Check the columns and if they have same values add that amount in the res
    for (int i =0; i<n; i++) {
        vector<int> colValues;
        for (int j = 0; j< n; j++) {
            colValues.push_back(grid[j][i]);
        }
        if (rows.find(colValues)!=rows.end()) {
            res += rows[colValues];
        }
    }
    return res;
    }
};