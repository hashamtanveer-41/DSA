class Solution {
public:
    void reverseString(vector<char>& s) {
       stack<char> f;
    for (int i =0; i<s.size(); i++)
        f.push(s[i]);
    for (int i =0; i<s.size(); i++)
    {
        s[i] = f.top();
        f.pop();
    }
    }
};