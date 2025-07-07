class Solution {
public:
    string customSortString(string order, string s) {
        string temp=order;
        sort(s.begin(),s.end(),[&](const char a, const char b){
            return temp.find(a)<temp.find(b);
        });
        return s;
    }
};