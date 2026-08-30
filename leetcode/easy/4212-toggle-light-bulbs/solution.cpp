class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
    vector<bool> state(101, false);
    for (int bulb : bulbs) {
        if (state[bulb]==false)state[bulb] = true;
        else state[bulb]=false;
    }vector<int>res;
    for (int i =1; i<=100; i++) {
        if (state[i])res.push_back(i);
    }
    return res;
}
};