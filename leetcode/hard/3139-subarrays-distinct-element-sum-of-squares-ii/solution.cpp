class Solution {
    public:
    typedef long long ll;
int MOD = 1e9+7;
int n;
vector<ll> sqSumTree;
vector<ll> sumSeqTree;
vector<ll> lazyTree;
void lazyAddition(int i, int l, int r, int val) {
    int len = r - l +1;
    sqSumTree[i] += 2*val*sumSeqTree[i] + len*val*val;
    sumSeqTree[i] += len * val;
}
void updateRange (int start, int end, int i, int l, int r, int val) {
    if (lazyTree[i]!=0) {
        lazyAddition(i, l, r, lazyTree[i]);
        if (l!=r) {
            lazyTree[2*i+1] += lazyTree[i];
            lazyTree[2*i+2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }
    // out of range
    if (l>end || r<start || l>r) {
        return;
    }
    // completely with in range
    if (l>=start && r<=end) {
        lazyAddition(i, l, r, val);
        if (l!=r) {
            lazyTree[2*i+1] += val;
            lazyTree[2*i+2] += val;
        }
        return;
    }
    int mid = l + (r-l)/2;
    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1,r, val);
    sumSeqTree[i] = sumSeqTree[2*i+1] + sumSeqTree[2*i+2];
    sqSumTree[i] = sqSumTree[2*i+1] + sqSumTree[2*i+2];
}
int sumCounts(vector<int>& nums) {
    n = nums.size();
    sqSumTree.assign(4*n, 0);
    sumSeqTree.assign(4*n, 0);
    lazyTree.assign(4*n, 0);
    vector<int> lastSeenIdx(100001, -1);
    ll result = 0;
    for (int i=0; i<n; i++) {
        int start = lastSeenIdx[nums[i]] +1;
        int end = i;
        updateRange(start, end, 0, 0, n-1, 1);
        result =( result +  sqSumTree[0])% MOD;
        lastSeenIdx[nums[i]] = i;
    }
    return result;
}
};