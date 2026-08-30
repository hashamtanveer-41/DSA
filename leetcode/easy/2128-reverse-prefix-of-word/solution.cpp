class Solution {
public:
    string reversePrefix(string word, char ch) {
    int c = word.find(ch);
    if (c==-1)return word;
    reverse(word.begin(), word.begin()+c+1);
    return word;
}
};