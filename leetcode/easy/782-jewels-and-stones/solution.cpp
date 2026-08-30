class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
    unordered_map<char, int> f;
    for (int i = 0; i<jewels.length(); i++ )
    {
        f[jewels[i]];
    }
        for (int j = 0; j<stones.length(); j++)
        {
            if (f.find(stones[j]) != f.end())count++;
        }
    return count;
    }
};