class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> have; 
        unordered_map<char, int> need;

        for(int i= 0; i<magazine.size(); i++)have[magazine[i]]++;

        for(int i= 0; i<ransomNote.size(); i++){
            need[ransomNote[i]]++;
            if(need[ransomNote[i]]>have[ransomNote[i]])return false;
        }
        return true;
    }
};