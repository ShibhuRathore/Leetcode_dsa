class Solution {
public:
    string removeDuplicates(string s) {
        string temp = "";
        int j = -1;  // No characters in temp initially

        for (int i = 0; i < s.length(); i++) {
            // We guarantee j != -1 by making sure we never access temp[j] when j == -1
            if (j != -1 && temp[j] == s[i]) {
                temp.pop_back();
                j--;
            } else {
                temp.push_back(s[i]);
                j++;
            }
        }

        return temp;
    }
};
