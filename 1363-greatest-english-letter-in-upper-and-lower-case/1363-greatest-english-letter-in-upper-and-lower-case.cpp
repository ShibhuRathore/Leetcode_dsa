class Solution {
public:
    string greatestLetter(string s) {
        bool low[26], up[26];
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(islower(s[i])) low[s[i] - 'a'] = true;
            else up[s[i] - 'A'] = true;
        }
        for(char i = 'Z'; i >= 'A'; i--){
            if(up[i - 'A'] && low[i - 'A']) return string(1 , i);
        }
        return "";
    }
};