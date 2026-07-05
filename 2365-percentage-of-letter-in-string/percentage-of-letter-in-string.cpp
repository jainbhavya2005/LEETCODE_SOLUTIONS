class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char, int> m;
        for (char x : s) {
            m[x]++;
        }
       return m[letter] * 100 / s.size();
    }
};