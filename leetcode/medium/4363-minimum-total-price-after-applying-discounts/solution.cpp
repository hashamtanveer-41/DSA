class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
    sort(discounts.begin(), discounts.end());
    int left = prices.size()-1, right = discounts.size()-1;
    double sum = 0.00000;
    while (left>=0 && right >=0) {
        double val = (double)(prices[left] * (100 - discounts[right])) / 100.00000;
        sum += val;
        left--; right--;
    }
    while (left>=0) {
        sum += prices[left];
        left--;
    }
    return sum;
    }
};