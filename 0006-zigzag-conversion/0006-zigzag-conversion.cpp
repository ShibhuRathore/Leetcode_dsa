class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>s.length()) return s;

        bool dir=false; // false->top_to_bottom. true->bottom_to_top
        int currRow=0;
        vector<string>ans(numRows);
        for(auto &ch:s){
             ans[currRow]+=ch;
            if(currRow==0||currRow==numRows-1){
              dir=!dir;
            }
            currRow+=dir?1:-1;
        }
        string result;
      for(auto &row:ans){
        result+=row;
      }
      return result;
    }
};