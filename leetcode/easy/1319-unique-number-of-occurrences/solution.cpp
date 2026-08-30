class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int i=0; i<arr.size(); i++)
        freq[arr[i]]++;
    unordered_map<int, int> occurrences;
    for (auto var: freq) {
        if (occurrences.find(var.second) != occurrences.end()) {
            return false;
        }
        occurrences[var.second]++;
    }
    return true;
}
};