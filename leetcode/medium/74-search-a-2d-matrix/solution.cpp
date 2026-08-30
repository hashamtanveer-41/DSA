class Solution {
public:
    int rowFind(vector<vector<int>> a, int target, int rows)
{
    int low = 0, high = rows-1, res = -1;
    while(low<=high){
        int guess = (high + low) /2;
        if(a[guess][0]<=target){
            res = guess;
            low = guess +1;
        }else{
            high = guess -1;
        }
    }
    return res;
}
bool searchMatrix(vector<vector<int>>& a, int target)
{
    int n = a.size();
    int m = a[0].size();
    int low = 0, high = m-1, res = -1;
    int row = rowFind(a, target, n);
    if (row==-1)return false;

    while(low<=high){
        int guess = (high+low)/2;
        if(a[row][guess]==target)return true;
        if(a[row][guess]<target)low = guess+1;
        else{
            high = guess-1;
        }
    }
    return false;
}
};