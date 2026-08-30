class Solution {
public:
struct Data {
    int first;
    int second;
};
struct CompareData {
    bool operator()(const Data& a, const Data& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
    long long totalCost(vector<int>& costs, int k, int candidates) {
         priority_queue<Data, std::vector<Data>, CompareData> minHeap;
    int n = costs.size();
    long long cost = 0;
    int left =0, right = n-1;    int count = candidates;

    while (count-- && left<right) {
        minHeap.push({costs[left], left});
        left++;
        minHeap.push({costs[right], right});
        right--;
    }
    if (left==right && count==0){minHeap.push({costs[left], left}); left++;}
    while (k--) {
        Data d = minHeap.top();
        minHeap.pop();
        cost += d.first;
        if (left>right)continue;
        if (d.second<left) {
            minHeap.push({costs[left], left});
            left++;
        }else {
            minHeap.push({costs[right], right});
            right--;
        }
    }
    return cost;
    }
};