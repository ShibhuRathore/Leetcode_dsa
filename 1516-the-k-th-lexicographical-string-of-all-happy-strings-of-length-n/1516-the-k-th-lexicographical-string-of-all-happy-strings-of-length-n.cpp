class Solution {
public:

   void generate(int n, int k, vector<char>&charset,vector<string>&result,string &curr){
    if(curr.length()==n){
        result.push_back(curr);
        return;
    }

    for(auto&ch:charset){
        if(curr.empty()||curr.back()!=ch){
            curr.push_back(ch);
            generate(n,k,charset,result,curr);
            curr.pop_back();
        }
    }
   }
    string getHappyString(int n, int k) {
        vector<char>charset={'a','b','c'};
        vector<string>result;
        string curr="";
        generate(n,k,charset,result,curr);
      if (k > result.size()) return "";  // guard condition
        return result[k - 1];  
    }
};