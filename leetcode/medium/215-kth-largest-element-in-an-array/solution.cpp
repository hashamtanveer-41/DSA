class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int i;
    for(i=0; i<k; i++)pq.push(arr[i]);
    for(i=k; i<arr.size(); i++){
        if(arr[i]<=pq.top())
            continue;
        pq.pop();
        pq.push(arr[i]);
    }
    return pq.top();
}
};