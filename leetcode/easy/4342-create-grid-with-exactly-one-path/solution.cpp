class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        for(int i=0; i<m; i++){
            string s(n, '#');
            res.push_back(s);
        }
        int i =0, j=0;
        while(i<m && j<n){
            if(j==n-1){
                res[i][j] = '.';
                i++;
            }else{
                res[i][j]='.';
                j++;
            }
        }
        return res;
    }
};