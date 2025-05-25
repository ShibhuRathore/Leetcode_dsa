class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rm = ransomNote.size();
        int mg = magazine.size();
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int r = 0;

        for (int m = 0; m < mg && r < rm; m++) {
            if (ransomNote[r] == magazine[m]) {
                r++;
            }
        }
        if (r == rm) {
            return true;
        } else {
            return false;
        }
    }
};