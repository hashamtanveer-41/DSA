class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

    vector<vector<string>> res;
    string query = "";
    for (char c: searchWord) {
        query.push_back(c);
        int s = query.size();
        vector<string> temp;
        for (string product: products) {
            if (temp.size()==3)break;
            if (product.substr(0, s)==query)
                temp.push_back(product);
        }
        res.push_back(temp);
    }
    return res;
    }
};