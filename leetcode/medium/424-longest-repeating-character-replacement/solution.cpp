class Solution {
public:
    int characterReplacement(string s, int k) {
    int left = 0, right = 0, answer = 0, mostFreq = 0;
    unordered_map<char, int> mp;
    int n = s.size();
    while (right<n) {
        mp[s[right]]++;
        mostFreq = max(mostFreq, mp[s[right]]);
        int windowLength = right-left+1;
        int changes = windowLength - mostFreq;
        if (changes<=k) {
            answer = max(answer, windowLength);
        }else {
            mp[s[left]]--;
            left++;
        }
        right++;
    }
    return answer;
}
};