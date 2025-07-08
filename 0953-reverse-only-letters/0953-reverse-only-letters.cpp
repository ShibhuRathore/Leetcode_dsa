class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char>letters;
        for(auto &ch:s){
            if(isalpha(ch)){
                letters.push_back(ch);
            }
        }
        string ans="";
        // reverse(letters.begin(),letters.end());
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(isalpha(ch)){
                ans+=letters.back();
                letters.pop_back();
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};