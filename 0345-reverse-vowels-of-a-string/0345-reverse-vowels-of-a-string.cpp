class Solution {
public:
    string reverseVowels(string s) {
        vector<char>vowel;
        for(auto &ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                vowel.push_back(ch);
            }
        }
        
        string res="";
        for(auto&ch:s){
           if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                res+=vowel.back();
                vowel.pop_back();
            }
            else{

            res+=ch;
            }
        }
        return res;
    }
};