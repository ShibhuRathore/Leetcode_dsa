class Solution {
public:
    int addDigits(int num) {
      while(1){
        int result=0;

        while(num>0){
        result+=num%10;
        num=num/10;
      }
      if(result<10)return result;
      else{
        num=result;
      }
      }
    
      return -1;
    }};