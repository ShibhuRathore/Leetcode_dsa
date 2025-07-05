class Solution {
public:

    string removeDigit(string number, char digit) {
      string result="";
      for(int i=0;i<number.length();i++){
        if(number[i]==digit){
            string candidate=number.substr(0,i)+number.substr(i+1,number.length());
             if(candidate>result){
                result=candidate;
             }
        }
      }  
      return result;
    }
};