class Solution {
public:
    void dfsV(vector<vector<int>>& a, vector<bool>& check, int n, int k) {
            if (check[k]==false)return;

    check[k] = false;
    for (int i = 0; i< a[k].size(); i++) {
        dfsV(a, check, n, a[k][i]);
    }
}
vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> a(n);
    for (int i=0; i< invocations.size(); i++) {
        int src = invocations[i][0];
        int dest = invocations[i][1];
        a[src].push_back(dest);
    }
    vector<bool>check(n, true);
    dfsV(a, check, n, k);
    bool is = false;
    for (int i=0; i< n; i++) {
        if (check[i]==false)continue;
        for (int j =0; j< a[i].size(); j++) {
            if (check[a[i][j]]==false) {
                check[a[i][j]]=true;
                is = true;
            }
        }
    }
    vector<int>res;
    // Group cannot be removed iff one method outside calls it
    if (is) {
        for (int i=0; i<n; i++)res.push_back(i);
        return res;
    }
    // We have to remove the group
    for (int i=0; i<n; i++) {
        if (check[i]==true)res.push_back(i);
    }
    return res;
}
};