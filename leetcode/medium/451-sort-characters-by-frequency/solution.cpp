class Solution {
public:
    string frequencySort(string s) {
    int n = s.size();
    unordered_map<char, int> f;
    for(int i = 0; i<n; i++)
        f[s[i]]++;
    vector<pair<char, int>> temp;
    for(auto var:f){
        temp.push_back(var);
    }
    sort(temp.begin(), temp.end(), [](auto&a , auto&b){
               return a.second>b.second;

    });
    string res = "";
    for(auto & [ch, count]:temp){
        res.append(count, ch);
    }
    return res;
}

};