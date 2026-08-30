class Solution {
public:
   vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    
    for (int i = 0; i < spells.size(); i++) {
        long long minPotion = (success + spells[i] - 1) / spells[i];
        auto it = lower_bound(potions.begin(), potions.end(), minPotion);
        spells[i] = potions.end() - it;
    }
    return spells;
}
};