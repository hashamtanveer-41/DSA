class Solution {
public:
    bool checkIfPangram(string sentence) {
    int n = sentence.size();
    if (n<26)return false;
    // unordered_map<char, int> alphabets;
    //
    unordered_map<char, int > given;
    // int index = 1;
    // for (char c = 'a'; c <= 'z'; ++c) {
    //     alphabets[c] = index;
    //     index++;
    // }
    for (int i=0; i< sentence.size(); i++)
        given[sentence[i]]++;
    if (given.size()==26)return true;
    return false;
}
};