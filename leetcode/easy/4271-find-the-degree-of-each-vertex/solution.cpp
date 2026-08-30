class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int nodes = matrix.size();
    vector<int> res(nodes, 0);
    for (int i=0; i< nodes; i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            if (matrix[i][j]==1)res[i] +=1;
        }
    }
    return res;
    }
};