class Solution {
public:
    string largestNumber(vector<int>& nums) {
     
          vector<string>snums;
          for(auto&n:nums){
            snums.push_back(to_string(n));
          }
          sort(snums.begin(),snums.end(),[&](const string&a, const string&b){
                  string temp=a+b;
                  string temp2=b+a;
                  return temp>temp2;
          });
             if(snums[0]=="0") return "0";
            string result="";
          for(auto &ch:snums){
            result+=ch;
          }
          return result;
    }
};