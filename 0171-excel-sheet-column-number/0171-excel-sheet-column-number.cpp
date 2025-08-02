class Solution {
private:
 
public:
    int titleToNumber(string columnTitle) {
      long result=0;
      for(auto &ch:columnTitle){
            int value=ch-'A'+1;
            result=result*26+value;
      }
      return result;
    }
};